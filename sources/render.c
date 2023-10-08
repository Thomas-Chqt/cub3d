/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:12:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/08 20:06:26 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include <math.h>

void	render_minimap(void)
{
	put_context(cub3d()->mmap.ctx, cub3d()->mmap.pos);
	put_rect(sub_vi2vi2(mtos(cub3d()->player.pos),
			div_vi2vi2(cub3d()->mmap.px_psize, (t_vec2i){2, 2})),
		cub3d()->mmap.px_psize, RED);

	for (int y = 0; y < WIDTH; y++)
	{
		t_vec2f	raydir = add_vf2vf2(	cub3d()->player.dir,
										mul_vf2f(	cub3d()->player.plane,
													2 * (float)(y) / (float)WIDTH - 1));
		
		// t_vec2f	unit_dist = {
		// 	.x = sqrtf(1 + (raydir.y / raydir.x) * (raydir.y / raydir.x)),
		// 	.y = sqrtf(1 + (raydir.x / raydir.y) * (raydir.x / raydir.y))
		// };
		t_vec2f	unit_dist = {
			.x = fabsf(1 / raydir.x) ,
			.y = fabsf(1 / raydir.y)
		};
		t_vec2i	curr_tile = vf2tovi2(cub3d()->player.pos);
		t_vec2f	side_length = {0, 0};
		t_vec2i step;

		if (raydir.x < 0)
		{
			step.x = -1;
			side_length.x = (cub3d()->player.pos.x - (float)(curr_tile.x)) * unit_dist.x;
		}
		else
		{
			step.x = 1;
			side_length.x = ((float)(curr_tile.x + 1) - cub3d()->player.pos.x) * unit_dist.x;
		}
		if (raydir.y < 0)
		{
			step.y = -1;
			side_length.y = (cub3d()->player.pos.y - (float)(curr_tile.y)) * unit_dist.y;
		}
		else
		{
			step.y = 1;
			side_length.y = ((float)(curr_tile.y + 1) - cub3d()->player.pos.y) * unit_dist.y;
		}

		t_bool	hit = false;
		float	length = 0;
		while (hit == false && length < 100.0f)
		{
			if (side_length.x < side_length.y)
			{
				curr_tile.x += step.x;
				length = side_length.x;
				side_length.x += unit_dist.x;
			}
			else
			{
				curr_tile.y += step.y;
				length = side_length.y;
				side_length.y += unit_dist.y;
			}
			if (cub3d()->cubf.tiles[curr_tile.y][curr_tile.x] <= wal)
				hit = true;
		}

		put_line(mtos(
			cub3d()->player.pos), mtos(
			add_vf2vf2(
				cub3d()->player.pos,
				mul_vf2f(raydir, length))), RED);
	}
}
