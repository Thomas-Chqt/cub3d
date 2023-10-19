/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 12:11:25 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "casting.h"
#include "cubfile.h"

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

t_bool	wall_hit(t_rres *res, t_dda_data *ddata, void *data)
{
	t_cubf	*cubf;

	(void)res;
	cubf = (t_cubf *)data;
	if (ddata->curr_tile.x >= cubf->m_size.x)
		return (true);
	if (ddata->curr_tile.y >= cubf->m_size.y)
		return (true);
	if (ddata->curr_tile.x < 0 || ddata->curr_tile.y < 0)
		return (true);
	return (cubf->map[ddata->curr_tile.y][ddata->curr_tile.x] >= wall);
}

t_bool	sprite_hit(t_rres *res, t_dda_data *ddata, void *data)
{
	t_list	*curr;
	t_cub3d	*cub;

	cub = (t_cub3d *)data;
	curr = cub->sprite_list;
	while (curr != NULL)
	{
		if (vf2tovi2(((t_sprite *)curr->data)->pos).x
			== ddata->curr_tile.x
			&& vf2tovi2(((t_sprite *)curr->data)->pos).y
			== ddata->curr_tile.y && ((t_sprite *)curr->data)->hp > 0)
		{
			res->hit_sprite = curr->data;
			return (true);
		}
		curr = curr->next;
	}
	res->hit_sprite = NULL;
	if (ddata->curr_tile.x >= cub->cubfile->m_size.x)
		return (true);
	if (ddata->curr_tile.y >= cub->cubfile->m_size.y)
		return (true);
	if (ddata->curr_tile.x < 0 || ddata->curr_tile.y < 0)
		return (true);
	return (cub->cubfile->map[ddata->curr_tile.y][ddata->curr_tile.x] >= wall);
}
