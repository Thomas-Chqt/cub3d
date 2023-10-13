/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:31:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 17:21:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "casting.h"

static void		cast_ray(t_dda *data);
static t_dres	make_result(t_dda data);

void	run_dda(void)
{
	t_dda	dda_data[WIDTH];
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		dda_data[x] = init_dda(cub3d()->p_pos, add_vf2vf2(cub3d()->p_dir,
					mul_vf2f(cub3d()->p_plane,
						2 * (float)x / (float)WIDTH - 1)));
		x++;
	}
	x = 0;
	while (x < WIDTH)
	{
		cast_ray(dda_data + x);
		cub3d()->dda_res[x] = make_result(dda_data[x]);
		x++;
	}
}

static void	cast_ray(t_dda *data)
{
	while (1)
	{
		if (data->curr_length.x < data->curr_length.y)
		{
			data->curr_length.x += data->length_step.x;
			data->curr_tile.x += data->tile_step.x;
			data->curr_side = data->v_side;
		}
		else
		{
			data->curr_length.y += data->length_step.y;
			data->curr_tile.y += data->tile_step.y;
			data->curr_side = data->h_side;
		}
		if (cub3d()->map[data->curr_tile.y][data->curr_tile.x] >= wall)
			break ;
	}
}

static t_dres	make_result(t_dda data)
{
	t_dres	res;

	res.hit_side = data.curr_side;
	if (res.hit_side == data.v_side)
	{
		res.dist = data.curr_length.x - data.length_step.x;
		res.wall_x = data.start.y + res.dist * data.dir.y;
	}
	else
	{
		res.dist = data.curr_length.y - data.length_step.y;
		res.wall_x = data.start.x + res.dist * data.dir.x;
	}
	res.wall_x -= floorf(res.wall_x);
	return (res);
}
