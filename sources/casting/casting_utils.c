/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 20:45:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "casting.h"
#include "cubfile.h"

static void	set_tile_step(t_dda_data *dest);
static void	set_length_step(t_dda_data *dest);
static void	set_start_length(t_dda_data *dest);

t_dda_data	make_dda_data(t_vec2f start, t_vec2f dir)
{
	t_dda_data	data;

	data.start = start;
	data.dir = dir;
	set_tile_step(&data);
	data.curr_tile = vf2tovi2(data.start);
	set_length_step(&data);
	set_start_length(&data);
	data.h_side = no;
	data.v_side = we;
	if (data.dir.y > 0)
		data.h_side = so;
	if (data.dir.x > 0)
		data.v_side = ea;
	return (data);
}

static void	set_tile_step(t_dda_data *dest)
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

static void	set_length_step(t_dda_data *dest)
{
	dest->length_step = (t_vec2f){
		.x = fabsf(1 / dest->dir.x),
		.y = fabsf(1 / dest->dir.y)
	};
}

static void	set_start_length(t_dda_data *dest)
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

t_bool	sould_stop(t_rres *res, t_dda_data *data, t_cub3d *cub, t_bool sp)
{
	t_list		*curr;

	if (sp)
	{
		curr = cub->sprite_list;
		while (curr != NULL)
		{
			if (vf2tovi2(((t_sprite *)curr->data)->pos).x
				== data->curr_tile.x
				&& vf2tovi2(((t_sprite *)curr->data)->pos).y
				== data->curr_tile.y)
			{
				res->hit_sprite = curr->data;
				break ;
			}
			curr = curr->next;
		}
	}
	if (data->curr_tile.x >= cub->cubfile->m_size.x)
		return (true);
	if (data->curr_tile.y >= cub->cubfile->m_size.y)
		return (true);
	if (data->curr_tile.x < 0 || data->curr_tile.y < 0)
		return (true);
	return (cub->cubfile->map[data->curr_tile.y][data->curr_tile.x] >= wall);
}
