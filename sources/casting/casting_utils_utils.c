/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:03:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 14:47:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "casting.h"
#include "player.h"

void	set_tile_step(t_dda_data *dest)
{
	if (dest->dir.x < 0)
		dest->tile_step.x = -1;
	else
		dest->tile_step.x = 1;
	if (dest->dir.y < 0)
		dest->tile_step.y = -1;
	else
		dest->tile_step.y = 1;
}

void	set_length_step(t_dda_data *dest)
{
	dest->length_step = (t_vec2f){
		.x = fabsf(1 / dest->dir.x),
		.y = fabsf(1 / dest->dir.y)
	};
}

void	set_start_length(t_dda_data *dest)
{
	if (dest->dir.x < 0)
		dest->curr_length.x
			= (dest->start.x - dest->curr_tile.x) * dest->length_step.x;
	else
		dest->curr_length.x
			= (dest->curr_tile.x + 1.0 - dest->start.x) * dest->length_step.x;
	if (dest->dir.y < 0)
		dest->curr_length.y
			= (dest->start.y - dest->curr_tile.y) * dest->length_step.y;
	else
		dest->curr_length.y
			= (dest->curr_tile.y + 1.0 - dest->start.y) * dest->length_step.y;
}

t_bool	is_sprite_behind(t_sprite *sp, t_play *p)
{
	t_vec2f	relative_pos;
	float	inv_det;

	relative_pos = sub_vf2vf2(sp->pos, p->pos);
	inv_det = 1.0 / (p->plane.x * p->dir.y
			- p->dir.x * p->plane.y);
	return ((inv_det * (-p->plane.y * relative_pos.x
				+ p->plane.x * relative_pos.y)) <= 0);
}
