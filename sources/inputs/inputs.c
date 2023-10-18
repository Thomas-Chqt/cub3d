/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:59:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 21:00:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubfile.h"
#include "inputs.h"
#include "error.h"
#include "player.h"

int	setup_inputs(t_cub3d *cub)
{
	if (add_event(CMD_L_KEY, ON_KEYDOWN, (t_vf) & on_cmd_down, cub) != 0)
		return (set_error(MALLOC_ERROR), -1);
	if (add_event(CMD_L_KEY, ON_KEYUP, (t_vf) & on_cmd_up, cub) != 0)
		return (set_error(MALLOC_ERROR), -1);
	if (add_event(L_CLICK, ON_KEYDOWN, (t_vf) & on_l_click, cub) != 0)
		return (set_error(MALLOC_ERROR), -1);
	hide_mouse();
	cub->is_m_block = true;
	cub->prev_mpos = mouse_pos();
	return (0);
}

void	input_loop(t_cub3d *cub)
{
	int	key;

	while ((poll_key(&key)))
	{
		if (key == W_KEY)
			pmove_fb(cub->player, 0.1f, cub->cubfile);
		if (key == S_KEY)
			pmove_fb(cub->player, -0.1f, cub->cubfile);
		if (key == D_KEY)
			pmove_lr(cub->player, 0.1f, cub->cubfile);
		if (key == A_KEY)
			pmove_lr(cub->player, -0.1f, cub->cubfile);
		if (key == LEFT_KEY)
			protate(cub->player, -0.1f);
		if (key == RIGHT_KEY)
			protate(cub->player, 0.1f);
	}
}

void	mouse_loop(t_cub3d *cub)
{
	int	dx;

	if (cub->is_m_block == false)
		return ;
	dx = sub_vi2vi2(mouse_pos(), cub->prev_mpos).x;
	protate(cub->player, 0.001 * dx);
	set_mouse_pos((t_vec2i){
		.x = WIDTH / 2,
		.y = HEIGHT / 2
	});
	cub->prev_mpos = mouse_pos();
}
