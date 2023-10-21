/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:59:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 21:33:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inputs_internal.h"

static void	handle_mouse(t_cub3d *cub);

int	setup_inputs(t_cub3d *cub)
{
	if (add_event(CMD_L_KEY, ON_KEYDOWN, (t_a)on_cmd_down, cub) != 0)
		return (set_error(MALLOC_ERROR), -1);
	if (add_event(CMD_L_KEY, ON_KEYUP, (t_a)on_cmd_up, cub) != 0)
		return (set_error(MALLOC_ERROR), -1);
	if (add_event(L_CLICK, ON_KEYDOWN, (t_a)on_l_click, cub) != 0)
		return (set_error(MALLOC_ERROR), -1);
	hide_mouse();
	cub->is_m_block = true;
	cub->prev_mpos = mouse_pos();
	return (0);
}

void	handle_inputs(t_cub3d *cub)
{
	int	key;

	while ((poll_key(&key)))
	{
		if (key == W_KEY)
			;
		if (key == S_KEY)
			;
		if (key == D_KEY)
			;
		if (key == A_KEY)
			;
		if (key == LEFT_KEY)
			;
		if (key == RIGHT_KEY)
			;
	}
	handle_mouse(cub);
}

static void	handle_mouse(t_cub3d *cub)
{
	int	dx;

	if (cub->is_m_block == false)
		return ;
	dx = sub_vi2vi2(mouse_pos(), cub->prev_mpos).x;
	set_mouse_pos((t_vec2i){
		.x = WIDTH / 2,
		.y = HEIGHT / 2
	});
	(void)dx;
	cub->prev_mpos = mouse_pos();
}
