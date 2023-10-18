/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:31:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 20:50:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "casting.h"
#include "error.h"
#include "player.h"
#include "cubfile.h"

static void	cast_ray(t_rres *res, t_dda_data data, t_cub3d *cub, t_bool sp);

int	setup_casting(t_dda **dest)
{
	t_dda	*dda;

	dda = malloc(sizeof(t_dda));
	if (dda == NULL)
		return (set_error(MALLOC_ERROR), -1);
	*dest = dda;
	return (0);
}

void	run_dda(t_dda *res, t_play *player, t_cub3d *cub)
{
	float	tmp;
	t_vec2f	dir;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		tmp = 2 * (float)x / (float)WIDTH - 1;
		dir = add_vf2vf2(player->dir, mul_vf2f(player->plane, tmp));
		cast_ray(res->rres + x, make_dda_data(player->pos, dir), cub, false);
		x++;
	}
}

t_sprite	*dda_one_ray(t_vec2f start, t_vec2f dir, t_cub3d *cub)
{
	t_rres	res;

	res.hit_sprite = NULL;
	cast_ray(&res, make_dda_data(start, dir), cub, true);
	return (res.hit_sprite);
}

static void	cast_ray(t_rres *res, t_dda_data data, t_cub3d *cub, t_bool sp)
{
	while (sould_stop(res, &data, cub, sp) == false)
	{
		if (data.curr_length.x < data.curr_length.y)
		{
			res->dist = data.curr_length.x;
			data.curr_length.x += data.length_step.x;
			data.curr_tile.x += data.tile_step.x;
			res->hit_side = data.v_side;
			res->wall_x = data.start.y + res->dist * data.dir.y;
		}
		else
		{
			res->dist = data.curr_length.y;
			data.curr_length.y += data.length_step.y;
			data.curr_tile.y += data.tile_step.y;
			res->hit_side = data.h_side;
			res->wall_x = data.start.x + res->dist * data.dir.x;
		}
	}
	res->wall_x -= floorf(res->wall_x);
	res->dir = data.dir;
}

void	clean_casting(t_dda *dda)
{
	free(dda);
}
