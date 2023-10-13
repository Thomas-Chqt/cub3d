/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:42:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 22:42:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "minimap.h"

t_vec2i	mtos(t_vec2f vect, t_vec2i mmap_pos)
{
	return (
		vf2tovi2(
			add_vf2vi2 (
				mul_vf2vi2(
					vect,
					mmap_tile_pxsize()
				),
				mmap_pos
			)
		)
	);
}

t_wall	init_wall_data(t_dres dda_res)
{
	t_wall	ret;

	ret.wall_h = (int)(HEIGHT / dda_res.dist);
	if (ret.wall_h >= HEIGHT)
	{
		ret.wall_srt = 0;
		ret.wall_end = HEIGHT;
	}
	else
	{
		ret.wall_srt = HEIGHT / 2 - ret.wall_h / 2;
		ret.wall_end = HEIGHT / 2 + ret.wall_h / 2;
	}
	ret.wall_x = dda_res.wall_x;
	if (dda_res.hit_side == no)
		ret.tex = cub3d()->no_tex;
	if (dda_res.hit_side == so)
		ret.tex = cub3d()->so_tex;
	if (dda_res.hit_side == ea)
		ret.tex = cub3d()->ea_tex;
	if (dda_res.hit_side == we)
		ret.tex = cub3d()->we_tex;
	return (ret);
}

t_uint32	tex_px(t_wall walda, t_vec2i pos)
{
	static t_ctx	*tex;
	static float	wall_x;
	static float	tex_step;
	static t_vec2f	text_curr;

	if (walda.tex != tex || wall_x != walda.wall_x)
	{
		tex = walda.tex;
		wall_x = walda.wall_x;
		tex_step = (float)ctx_size(tex).y / (float)walda.wall_h;
		text_curr = (t_vec2f){
			walda.wall_x * (float)ctx_size(tex).x,
			(pos.y - (HEIGHT / 2 - walda.wall_h / 2)) * tex_step
		};
		return (ctx_px(tex, vf2tovi2(text_curr)));
	}
	text_curr.y += tex_step;
	return (ctx_px(tex, vf2tovi2(text_curr)));
}
