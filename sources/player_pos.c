/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:28:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/08 17:56:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ppos(t_vec2f pos)
{
	cub3d()->player.pos = pos;
}

void	pmov_x(float dist)
{
	set_ppos((t_vec2f){
		cub3d()->player.pos.x + dist,
		cub3d()->player.pos.y
	});
}

void	pmov_y(float dist)
{
	set_ppos((t_vec2f){
		cub3d()->player.pos.x,
		cub3d()->player.pos.y + dist
	});
}

void	pmov_f(float dist)
{
	set_ppos(
		add_vf2vf2(
			cub3d()->player.pos,
			mul_vf2f(cub3d()->player.dir, dist)
			)
		);
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
