/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:48:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/09 22:09:49 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "dda.h"

static void	cast_ray(t_dda *dest, t_side v_side, t_side h_side);

void	run_dda(void)
{
	int		x;
	t_dda	*dest;

	x = -1;
	while (++x < WIDTH)
	{
		dest = &cub3d()->dda_res[x];
		dest->start = cub3d()->player.pos;
		dest->dir = get_ray_dir(x);
		set_tile_step(dest);
		dest->curr_tile = vf2tovi2(dest->start);
		set_length_step(dest);
		set_start_length(dest);
		if (dest->dir.x > 0 && dest->dir.y <= 0)
			cast_ray(dest, ea, no);
		if (dest->dir.x > 0 && dest->dir.y > 0)
			cast_ray(dest, ea, so);
		if (dest->dir.x <= 0 && dest->dir.y > 0)
			cast_ray(dest, we, so);
		if (dest->dir.x <= 0 && dest->dir.y <= 0)
			cast_ray(dest, we, no);
	}
}

static void	cast_ray(t_dda *dest, t_side v_side, t_side h_side)
{
	while (1)
	{
		if (dest->curr_length.x < dest->curr_length.y)
		{
			dest->curr_length.x += dest->length_step.x;
			dest->curr_tile.x += dest->tile_step.x;
			dest->hit_side = v_side;
		}
		else
		{
			dest->curr_length.y += dest->length_step.y;
			dest->curr_tile.y += dest->tile_step.y;
			dest->hit_side = h_side;
		}
		if (cub3d()->cubf.tiles[dest->curr_tile.y][dest->curr_tile.x] <= wal)
			break ;
	}
	if (dest->hit_side == v_side)
		dest->dist = dest->curr_length.x - dest->length_step.x;
	else
		dest->dist = dest->curr_length.y - dest->length_step.y;
}
