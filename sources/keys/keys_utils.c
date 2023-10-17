/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:12:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 19:14:40 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

#include "sprite.h"

void	on_cmd_down(void *none)
{
	(void)none;
	show_mouse();
	cub3d()->is_m_block = false;
	desac_poll_key();
}

void	on_cmd_up(void *none)
{
	(void)none;
	hide_mouse();
	cub3d()->is_m_block = true;
	react_poll_key();
}

void	on_l_click(void *none)
{
	(void)none;
	if (cub3d()->dda_res[WIDTH / 2].first_hit != NULL)
		play_anim(cub3d()->dda_res[WIDTH / 2].first_hit,
			cub3d()->dda_res[WIDTH / 2].first_hit->die_anime);
}
