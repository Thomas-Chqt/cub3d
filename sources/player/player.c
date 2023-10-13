/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:12:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 16:18:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"

void	pmove_fb(float dist)
{
	t_vec2f	*ppos_ptr;
	t_vec2f	mov_vec;

	ppos_ptr = &cub3d()->p_pos;
	mov_vec = mul_vf2f(cub3d()->p_dir, dist);
	if (!is_in_wall((t_vec2f){ppos_ptr->x + mov_vec.x, ppos_ptr->y}))
		*ppos_ptr = (t_vec2f){ppos_ptr->x + mov_vec.x, ppos_ptr->y};
	if (!is_in_wall((t_vec2f){ppos_ptr->x, ppos_ptr->y + mov_vec.y}))
		*ppos_ptr = (t_vec2f){ppos_ptr->x, ppos_ptr->y + mov_vec.y};
}

void	pmove_lr(float dist)
{
	t_vec2f	*ppos_ptr;
	t_vec2f	mov_vec;

	ppos_ptr = &cub3d()->p_pos;
	mov_vec = mul_vf2f(cub3d()->p_plane, dist);
	if (!is_in_wall((t_vec2f){ppos_ptr->x + mov_vec.x, ppos_ptr->y}))
		*ppos_ptr = (t_vec2f){ppos_ptr->x + mov_vec.x, ppos_ptr->y};
	if (!is_in_wall((t_vec2f){ppos_ptr->x, ppos_ptr->y + mov_vec.y}))
		*ppos_ptr = (t_vec2f){ppos_ptr->x, ppos_ptr->y + mov_vec.y};
}

void	protate(float rad)
{
	t_vec2f	*dir;
	t_vec2f	*plane;

	dir = &(cub3d()->p_dir);
	plane = &(cub3d()->p_plane);
	*dir = rot_vf2(cub3d()->p_dir, rad);
	*plane = rot_vf2(cub3d()->p_plane, rad);
}
