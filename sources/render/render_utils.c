/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:42:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/16 18:08:38 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "minimap.h"

t_vec2i	mtomm(t_vec2f vect, t_vec2i mmap_pos)
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
	int		wall_h;
	t_ctx	*tex;
	t_wall	ret;

	wall_h = (int)(HEIGHT / dda_res.dist);
	ret.wall_srt = HEIGHT / 2 - wall_h / 2;
	ret.wall_end = HEIGHT / 2 + wall_h / 2;
	if (dda_res.hit_side == no)
		tex = cub3d()->no_tex;
	if (dda_res.hit_side == so)
		tex = cub3d()->so_tex;
	if (dda_res.hit_side == ea)
		tex = cub3d()->ea_tex;
	if (dda_res.hit_side == we)
		tex = cub3d()->we_tex;
	ret.stripe = ctx_vstripe(tex, dda_res.wall_x * ctx_size(tex).x);
	return (ret);
}

t_vec2i	transform_sppos(t_sprite *sp, float *dist)
{
	t_vec2f	relative_pos;
	float	inv_det;
	float	transform_x;
	float	transform_y;

	relative_pos = sub_vf2vf2(sp->pos, cub3d()->p_pos);
	inv_det = 1.0 / (cub3d()->p_plane.x * cub3d()->p_dir.y
			- cub3d()->p_dir.x * cub3d()->p_plane.y);
	transform_x = inv_det * (cub3d()->p_dir.y * relative_pos.x
			- cub3d()->p_dir.x * relative_pos.y);
	transform_y = inv_det * (-cub3d()->p_plane.y * relative_pos.x
			+ cub3d()->p_plane.x * relative_pos.y);
	*dist = transform_y;
	return ((t_vec2i){
		.x = (int)((WIDTH / 2) * (1 + transform_x / transform_y)),
		.y = (HEIGHT / 2)
	});
}
