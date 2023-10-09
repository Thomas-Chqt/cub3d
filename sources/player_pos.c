/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:28:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/09 23:29:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"

void	set_ppos(t_vec2f pos)
{
	if (is_in_wall(pos))
		return ;
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
	t_vec2f	mov_vec;

	mov_vec = mul_vf2f(cub3d()->player.dir, dist);
	pmov_x(mov_vec.x);
	pmov_y(mov_vec.y);
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
