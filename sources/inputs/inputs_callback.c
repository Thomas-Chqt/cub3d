/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:02:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 20:27:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inputs_internal.h"

void	on_cmd_down(t_cub3d *cub)
{
	show_mouse();
	cub->is_m_block = false;
	desac_poll_key();
}

void	on_cmd_up(t_cub3d *cub)
{
	hide_mouse();
	set_mouse_pos((t_vec2i){
		.x = WIDTH / 2,
		.y = HEIGHT / 2
	});
	cub->is_m_block = true;
	react_poll_key();
}

void	on_l_click(t_cub3d *cub)
{
	ent_shoot(cub->p_ref, cub->ent_lst, cub);
}

void	on_f_down(t_cub3d *cub)
{
	t_vec2i	door_pos;

	door_pos = vf2tovi2(add_vf2vf2(ent_pos(cub->p_ref), ent_dir(cub->p_ref)));
	if (door_pos.x == (int)ent_pos(cub->p_ref).x
		&& door_pos.y == (int)ent_pos(cub->p_ref).y)
		return ;
	toggle_door(cub->cubf, door_pos);
}
