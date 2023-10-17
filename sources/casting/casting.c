/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:31:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 18:59:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "casting.h"

static void	cast_ray(t_dda *data, t_dres *res);

void	run_dda(void)
{
	float	tmp;
	t_vec2f	dir;
	t_dda	dda_data[WIDTH];
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		tmp = 2 * (float)x / (float)WIDTH - 1;
		dir = add_vf2vf2(cub3d()->p_dir, mul_vf2f(cub3d()->p_plane, tmp));
		dda_data[x] = init_dda(cub3d()->p_pos, dir);
		cub3d()->dda_res[x] = (t_dres){};
		cast_ray(dda_data + x, cub3d()->dda_res + x);
		x++;
	}
}

static void	cast_ray(t_dda *data, t_dres *res)
{
	while (sould_stop(data, res) == false)
	{
		if (data->curr_length.x < data->curr_length.y)
		{
			res->dist = data->curr_length.x;
			data->curr_length.x += data->length_step.x;
			data->curr_tile.x += data->tile_step.x;
			res->hit_side = data->v_side;
			res->wall_x = data->start.y + res->dist * data->dir.y;
		}
		else
		{
			res->dist = data->curr_length.y;
			data->curr_length.y += data->length_step.y;
			data->curr_tile.y += data->tile_step.y;
			res->hit_side = data->h_side;
			res->wall_x = data->start.x + res->dist * data->dir.x;
		}
	}
	return ((void)(res->wall_x -= floorf(res->wall_x), res->dir = data->dir));
}
