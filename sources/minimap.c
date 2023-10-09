/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:04:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/09 22:54:40 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

static void	draw_minimap(void);

int	make_minimap(t_vec2i size, t_vec2i pos)
{
	t_ctx	**pctx;

	pctx = &cub3d()->mmap.p_ctx;
	cub3d()->mmap.ctx = new_context(size);
	if (cub3d()->mmap.ctx == NULL)
		return (set_error(MALLOC_ERROR), -1);
	clear_ctx(cub3d()->mmap.ctx);
	cub3d()->mmap.pos = pos;
	draw_minimap();
	*pctx = new_context((t_vec2i){
			tile_size_px().x / 4,
			tile_size_px().y / 4
		});
	if (*pctx == NULL)
		return (free_minimap(&cub3d()->mmap),
			set_error(MALLOC_ERROR), -1);
	fill_ctx(*pctx, RED);
	return (0);
}

t_vec2i	tile_size_px(void)
{
	static t_vec2i	tile_size = {-1, -1};
	t_vec2f			ratio;

	if (tile_size.x == -1 && tile_size.y == -1)
	{
		ratio.x = (float)ctx_size(cub3d()->mmap.ctx).x
			/ (float)cub3d()->cubf.size.x;
		ratio.y = (float)ctx_size(cub3d()->mmap.ctx).y
			/ (float)cub3d()->cubf.size.y;
		if (ratio.x < ratio.y)
			tile_size = (t_vec2i){(int)ratio.x, (int)ratio.x};
		else
			tile_size = (t_vec2i){(int)ratio.y, (int)ratio.y};
	}
	return (tile_size);
}

void	free_minimap(t_mmap *mmap)
{
	free_context(mmap->ctx);
	free_context(mmap->p_ctx);
}

static void	draw_minimap(void)
{
	t_vec2i	curr;

	curr.y = 0;
	while (curr.y < cub3d()->cubf.size.y)
	{
		curr.x = 0;
		while (curr.x < cub3d()->cubf.size.x)
		{
			if (cub3d()->cubf.tiles[curr.y][curr.x] > wal)
				draw_rect(cub3d()->mmap.ctx,
					mul_vi2vi2(curr, tile_size_px()), tile_size_px(), WHITE);
			else if (cub3d()->cubf.tiles[curr.y][curr.x] == wal)
				draw_rect(cub3d()->mmap.ctx,
					mul_vi2vi2(curr, tile_size_px()), tile_size_px(), BLACK);
			curr.x++;
		}
		curr.y++;
	}
}
