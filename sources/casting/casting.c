/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:31:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 13:44:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "casting.h"
#include "error.h"
#include "player.h"
#include "cubfile.h"

typedef t_bool	(*t_hit_func)(t_rres *, t_dda_data *, void *);

static void	cast_ray(t_rres *res, t_dda_data ddata, t_hit_func hit, void *d);

int	setup_casting(t_dda **dest)
{
	t_dda	*dda;

	dda = malloc(sizeof(t_dda));
	if (dda == NULL)
		return (set_error(MALLOC_ERROR), -1);
	*dest = dda;
	return (0);
}

void	run_dda(t_dda *res, t_play *player, t_cubf *cubf)
{
	float	tmp;
	t_vec2f	dir;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		tmp = 2 * (float)x / (float)WIDTH - 1;
		dir = add_vf2vf2(player->dir, mul_vf2f(player->plane, tmp));
		cast_ray(
			res->rres + x,
			make_dda_data(player->pos, dir),
			&wall_hit,
			cubf);
		x++;
	}
}

t_sprite	*dda_sprite(t_play *player, t_cub3d *cub)
{
	t_rres	res;

	cast_ray(
		&res,
		make_dda_data(player->pos, player->dir),
		&sprite_hit,
		cub);
	return (res.hit_sprite);
}

static void	cast_ray(t_rres *res, t_dda_data ddata, t_hit_func hit, void *d)
{
	while (hit(res, &ddata, d) == false)
	{
		if (ddata.curr_length.x < ddata.curr_length.y)
		{
			res->dist = ddata.curr_length.x;
			ddata.curr_length.x += ddata.length_step.x;
			ddata.curr_tile.x += ddata.tile_step.x;
			res->hit_side = ddata.v_side;
			res->wall_x = ddata.start.y + res->dist * ddata.dir.y;
		}
		else
		{
			res->dist = ddata.curr_length.y;
			ddata.curr_length.y += ddata.length_step.y;
			ddata.curr_tile.y += ddata.tile_step.y;
			res->hit_side = ddata.h_side;
			res->wall_x = ddata.start.x + res->dist * ddata.dir.x;
		}
	}
	res->wall_x -= floorf(res->wall_x);
	res->dir = ddata.dir;
}
