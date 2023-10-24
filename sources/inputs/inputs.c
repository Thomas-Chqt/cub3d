/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:59:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 20:00:07 by tchoquet         ###   ########.fr       */
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
	if (add_event(F_KEY, ON_KEYDOWN, (t_a)on_f_down, cub) != 0)
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
			mov_ent(cub->cubf, cub->p_ref,
				mul_vf2f(ent_dir(cub->p_ref), 0.1));
		if (key == S_KEY)
			mov_ent(cub->cubf, cub->p_ref,
				mul_vf2f(ent_dir(cub->p_ref), -0.1));
		if (key == D_KEY)
			mov_ent(cub->cubf, cub->p_ref,
				mul_vf2f(rot_vf2(ent_dir(cub->p_ref), M_PI / 2), 0.1));
		if (key == A_KEY)
			mov_ent(cub->cubf, cub->p_ref,
				mul_vf2f(rot_vf2(ent_dir(cub->p_ref), M_PI / 2), -0.1));
		if (key == LEFT_KEY)
			rot_ent(cub->p_ref, -0.1);
		if (key == RIGHT_KEY)
			rot_ent(cub->p_ref, 0.1);
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
	rot_ent(cub->p_ref, 0.001 * dx);
	cub->prev_mpos = mouse_pos();
}
