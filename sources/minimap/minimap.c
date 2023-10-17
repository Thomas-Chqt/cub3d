/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:20:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 12:55:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"
#include "error.h"

static void	draw_mmap_tiles(t_ctx *ctx);

int	init_minimap(t_vec2i size)
{
	t_ctx	**pctx;
	t_ctx	**rctx;

	pctx = &cub3d()->mmap_p_ctx;
	rctx = &cub3d()->rays_ctx;
	cub3d()->mmap_ctx = new_context(size);
	if (cub3d()->mmap_ctx == NULL)
		return (set_error(MALLOC_ERROR), -1);
	draw_mmap_tiles(cub3d()->mmap_ctx);
	*pctx = new_context((t_vec2i){
			mmap_tile_pxsize().x / 4,
			mmap_tile_pxsize().y / 4});
	if (*pctx == NULL)
		return (free_context(cub3d()->mmap_ctx), set_error(MALLOC_ERROR), -1);
	fill_ctx(*pctx, RED);
	*rctx = new_context(size);
	if (*rctx == NULL)
		return (free_context(cub3d()->mmap_ctx), free_context(*pctx),
			set_error(MALLOC_ERROR), -1);
	return (0);
}

static void	draw_mmap_tiles(t_ctx *ctx)
{
	t_vec2i	curr;

	curr.y = 0;
	while (curr.y < cub3d()->m_size.y)
	{
		curr.x = 0;
		while (curr.x < cub3d()->m_size.x)
		{
			if (cub3d()->map[curr.y][curr.x] < 0)
				draw_rect(ctx, mul_vi2vi2(curr, mmap_tile_pxsize()),
					mmap_tile_pxsize(), WHITE);
			else if (cub3d()->map[curr.y][curr.x] > 0)
				draw_rect(ctx, mul_vi2vi2(curr, mmap_tile_pxsize()),
					mmap_tile_pxsize(), BLACK);
			curr.x++;
		}
		curr.y++;
	}
}
