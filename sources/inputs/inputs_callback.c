/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:02:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 19:33:35 by tchoquet         ###   ########.fr       */
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
	(void)cub;
}
