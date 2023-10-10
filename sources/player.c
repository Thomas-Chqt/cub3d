/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:49:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/10 12:00:12 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"

void	init_player(void)
{
	t_vec2f	*ppos_ptr;

	ppos_ptr = &cub3d()->player.pos;
	*ppos_ptr = add_vf2vf2(
			vi2tovf2(cub3d()->cubf.p_start),
			(t_vec2f){0.5, 0.5});
	cub3d()->player.dir = tile_to_vect_dir(cub3d()->cubf.p_start_rot);
	cub3d()->player.plane = tile_to_vect_plane(cub3d()->cubf.p_start_rot);
}

void	pmove_fb(float dist)
{
	t_vec2f	*ppos_ptr;
	t_vec2f	mov_vec;

	ppos_ptr = &cub3d()->player.pos;
	mov_vec = mul_vf2f(cub3d()->player.dir, dist);
	if (!is_in_wall((t_vec2f){ppos_ptr->x + mov_vec.x, ppos_ptr->y}))
		*ppos_ptr = (t_vec2f){ppos_ptr->x + mov_vec.x, ppos_ptr->y};
	if (!is_in_wall((t_vec2f){ppos_ptr->x, ppos_ptr->y + mov_vec.y}))
		*ppos_ptr = (t_vec2f){ppos_ptr->x, ppos_ptr->y + mov_vec.y};
}

void	pmove_lr(float dist)
{
	t_vec2f	*ppos_ptr;
	t_vec2f	mov_vec;

	ppos_ptr = &cub3d()->player.pos;
	mov_vec = mul_vf2f(cub3d()->player.plane, dist);
	if (!is_in_wall((t_vec2f){ppos_ptr->x + mov_vec.x, ppos_ptr->y}))
		*ppos_ptr = (t_vec2f){ppos_ptr->x + mov_vec.x, ppos_ptr->y};
	if (!is_in_wall((t_vec2f){ppos_ptr->x, ppos_ptr->y + mov_vec.y}))
		*ppos_ptr = (t_vec2f){ppos_ptr->x, ppos_ptr->y + mov_vec.y};
}

void	protate(float rad)
{
	t_vec2f	*dir;
	t_vec2f	*plane;

	dir = &(cub3d()->player.dir);
	plane = &(cub3d()->player.plane);
	*dir = rot_vf2d(cub3d()->player.dir, rad);
	*plane = rot_vf2d(cub3d()->player.plane, rad);
}
