/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 17:19:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "casting.h"

static void	set_tile_step(t_dda *dest);
static void	set_length_step(t_dda *dest);
static void	set_start_length(t_dda *dest);

t_dda	init_dda(t_vec2f start, t_vec2f dir)
{
	t_dda	dda;

	dda.start = start;
	dda.dir = dir;
	set_tile_step(&dda);
	dda.curr_tile = vf2tovi2(dda.start);
	set_length_step(&dda);
	set_start_length(&dda);
	if (dda.dir.x > 0 && dda.dir.y <= 0)
		return (dda.v_side = ea, dda.h_side = no, dda);
	if (dda.dir.x > 0 && dda.dir.y > 0)
		return (dda.v_side = ea, dda.h_side = so, dda);
	if (dda.dir.x <= 0 && dda.dir.y > 0)
		return (dda.v_side = we, dda.h_side = so, dda);
	if (dda.dir.x <= 0 && dda.dir.y <= 0)
		return (dda.v_side = we, dda.h_side = no, dda);
	return (dda);
}

static void	set_tile_step(t_dda *dest)
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

static void	set_length_step(t_dda *dest)
{
	dest->length_step = (t_vec2f){
		.x = fabsf(1 / dest->dir.x),
		.y = fabsf(1 / dest->dir.y)
	};
}

static void	set_start_length(t_dda *dest)
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
