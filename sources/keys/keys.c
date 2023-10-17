/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:52:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 13:26:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"
#include "error.h"

int	init_keys(void)
{
	if (add_event(CMD_L_KEY, ON_KEYDOWN, &on_cmd_down, NULL) != 0)
		return (set_error(MALLOC_ERROR), -1);
	if (add_event(CMD_L_KEY, ON_KEYUP, &on_cmd_up, NULL) != 0)
		return (set_error(MALLOC_ERROR), -1);
	hide_mouse();
	cub3d()->is_m_block = true;
	cub3d()->prev_mpos = mouse_pos();
	return (0);
}

void	key_loop(int key)
{
	if (key == W_KEY)
		pmove_fb(0.1f);
	if (key == S_KEY)
		pmove_fb(-0.1f);
	if (key == D_KEY)
		pmove_lr(0.1f);
	if (key == A_KEY)
		pmove_lr(-0.1f);
	if (key == LEFT_KEY)
		protate(-0.1f);
	if (key == RIGHT_KEY)
		protate(0.1f);
}

void	mouse_rot(void)
{
	int	dx;

	if (cub3d()->is_m_block == false)
		return ;
	dx = sub_vi2vi2(mouse_pos(), cub3d()->prev_mpos).x;
	protate(0.001 * dx);
	set_mouse_pos((t_vec2i){
		.x = WIDTH / 2,
		.y = HEIGHT / 2
	});
	cub3d()->prev_mpos = mouse_pos();
}


