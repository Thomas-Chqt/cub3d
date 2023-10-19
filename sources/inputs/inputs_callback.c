/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:02:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 14:35:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubfile.h"
#include "inputs.h"
#include "sprite.h"
#include "casting.h"
#include "player.h"
#include "hud.h"

void	on_cmd_down(t_cub3d *cub)
{
	show_mouse();
	cub->is_m_block = false;
	desac_poll_key();
}

void	on_cmd_up(t_cub3d *cub)
{
	hide_mouse();
	cub->is_m_block = true;
	react_poll_key();
}

void	on_l_click(t_cub3d *cub)
{
	pshoot(cub->player, dda_sprite(cub->player, cub), cub->hud);
}
