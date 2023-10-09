/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:12:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/09 22:08:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	render_minimap(void)
{
	put_context(cub3d()->mmap.ctx, cub3d()->mmap.pos);
	put_context(cub3d()->mmap.p_ctx, sub_vi2vi2(mtos(cub3d()->player.pos),
			div_vi2vi2(ctx_size(cub3d()->mmap.p_ctx), (t_vec2i){2, 2})));
}
/*
for (int x = 0; x < WIDTH; x++)
{
	if (cub3d()->dda_res[x].hit_side == no)
	{
		put_line(
			mtos(cub3d()->player.pos),
			mtos(
				add_vf2vf2(cub3d()->player.pos, 
				mul_vf2f(cub3d()->dda_res[x].dir, cub3d()->dda_res[x].dist))),
			RED);
	}
	else if (cub3d()->dda_res[x].hit_side == so)
	{
		put_line(
			mtos(cub3d()->player.pos),
			mtos(
				add_vf2vf2(cub3d()->player.pos, 
				mul_vf2f(cub3d()->dda_res[x].dir, cub3d()->dda_res[x].dist))),
			GREEN);
	}
	else if (cub3d()->dda_res[x].hit_side == ea)
	{
		put_line(
			mtos(cub3d()->player.pos),
			mtos(
				add_vf2vf2(cub3d()->player.pos, 
				mul_vf2f(cub3d()->dda_res[x].dir, cub3d()->dda_res[x].dist))),
			BLUE);
	}
	else if (cub3d()->dda_res[x].hit_side == we)
	{
		put_line(
			mtos(cub3d()->player.pos),
			mtos(
				add_vf2vf2(cub3d()->player.pos, 
				mul_vf2f(cub3d()->dda_res[x].dir, cub3d()->dda_res[x].dist))),
			BLACK);
	}
}
*/
