/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:04:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 20:29:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

static t_wh	get_tile_size(t_cubf *cubf, t_wh to_fit);
static void	draw_minimap(t_minimap *mmap, t_cubf *cubf);

int	make_minimap(t_minimap *mmap, t_cubf *cubf, t_wh size, t_pos pos)
{
	mmap->ctx = new_context(size);
	if (mmap->ctx == NULL)
		return (set_error(MALLOC_ERROR), -1);
	mmap->pos = pos;
	mmap->ti_size = get_tile_size(cubf, size);
	draw_minimap(mmap, cubf);
	mmap->p_ctx = new_context(divwhi(mmap->ti_size, 4));
	if (mmap->p_ctx == NULL)
		return (set_error(MALLOC_ERROR), free_minimap(mmap), -1);
	fill_ctx(mmap->p_ctx, RED);
	mmap->p_size = 1.0f / 4.0f;
	mmap->ray_ctx = new_context(ctx_size(mmap->ctx));
	if (mmap->ray_ctx == NULL)
		return (set_error(MALLOC_ERROR), free_minimap(mmap), -1);
	return (0);
}

void	free_minimap(t_minimap	*mmap)
{
	delete_ctx(mmap->ctx);
	delete_ctx(mmap->p_ctx);
	delete_ctx(mmap->ray_ctx);
}

static t_wh	get_tile_size(t_cubf *cubf, t_wh to_fit)
{
	float	r_w;
	float	r_h;

	r_w = (float)to_fit.w / (float)cubf->size.w;
	r_h = (float)to_fit.h / (float)cubf->size.h;
	if (r_w < r_h)
		return ((t_wh){(int)r_w, (int)r_w});
	else
		return ((t_wh){(int)r_h, (int)r_h});
}

static void	draw_minimap(t_minimap *mmap, t_cubf *cubf)
{
	t_pos	curr;

	curr.y = 0;
	while (curr.y < cubf->size.h)
	{
		curr.x = 0;
		while (curr.x < cubf->size.w)
		{
			if (cubf->tiles[curr.y][curr.x] > wal)
				put_rect(mmap->ctx, mmap->ti_size,
					mulposwh(curr, mmap->ti_size), WHITE);
			else if (cubf->tiles[curr.y][curr.x] == wal)
				put_rect(mmap->ctx, mmap->ti_size,
					mulposwh(curr, mmap->ti_size), BLACK);
			curr.x++;
		}
		curr.y++;
	}
}
