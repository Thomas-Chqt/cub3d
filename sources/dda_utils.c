/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 00:14:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/09 19:55:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "dda.h"

t_vec2f	get_ray_dir(int x)
{
	t_vec2f	dir;

	dir = add_vf2vf2(
			cub3d()->player.dir,
			mul_vf2f(
				cub3d()->player.plane,
				2 * (float)x / (float)WIDTH - 1));
	return (dir);
}

void	set_tile_step(t_dda *dest)
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

void	set_length_step(t_dda *dest)
{
	dest->length_step = (t_vec2f){
		.x = fabsf(1 / dest->dir.x),
		.y = fabsf(1 / dest->dir.y)
	};
}

void	set_start_length(t_dda *dest)
{
	if (dest->dir.x < 0)
		dest->curr_length.x = (dest->start.x - dest->curr_tile.x)
			* dest->length_step.x;
	else
		dest->curr_length.x = (dest->curr_tile.x + 1.0 - dest->start.x)
			* dest->length_step.x;
	if (dest->dir.y < 0)
		dest->curr_length.y = (dest->start.y - dest->curr_tile.y)
			* dest->length_step.y;
	else
		dest->curr_length.y = (dest->curr_tile.y + 1.0 - dest->start.y)
			* dest->length_step.y;
}
