/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_callback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:02:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 21:00:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubfile.h"
#include "inputs.h"
#include "sprite.h"
#include "casting.h"
#include "player.h"

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
	t_sprite	*hit;

	hit = dda_one_ray(cub->player->pos, cub->player->dir, cub);
	if (hit == NULL)
		return ;
	sp_take_damage(hit, 100, cub->animations);
}
