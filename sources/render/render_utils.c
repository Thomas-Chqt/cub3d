/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:42:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 18:09:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "cubfile.h"
#include "sprite.h"
#include "player.h"

t_wall	init_wall_data(t_rres ray_res, t_cubf *cubf)
{
	int		wall_h;
	t_ctx	*tex;
	t_wall	ret;

	wall_h = (int)(HEIGHT / ray_res.dist);
	ret.wall_srt = HEIGHT / 2 - wall_h / 2;
	ret.wall_end = HEIGHT / 2 + wall_h / 2;
	if (ray_res.hit_side == no)
		tex = cubf->no_tex;
	if (ray_res.hit_side == so)
		tex = cubf->so_tex;
	if (ray_res.hit_side == ea)
		tex = cubf->ea_tex;
	if (ray_res.hit_side == we)
		tex = cubf->we_tex;
	ret.stripe = ctx_vstripe(tex, ray_res.wall_x * ctx_size(tex).x);
	return (ret);
}

t_vec2i	transform_sppos(t_sprite *sp, float *dist, t_play *p)
{
	t_vec2f	relative_pos;
	float	inv_det;
	float	transform_x;
	float	transform_y;

	relative_pos = sub_vf2vf2(sp->pos, p->pos);
	inv_det = 1.0 / (p->plane.x * p->dir.y
			- p->dir.x * p->plane.y);
	transform_x = inv_det * (p->dir.y * relative_pos.x
			- p->dir.x * relative_pos.y);
	transform_y = inv_det * (-p->plane.y * relative_pos.x
			+ p->plane.x * relative_pos.y);
	*dist = transform_y;
	return ((t_vec2i){
		.x = (int)((WIDTH / 2) * (1 + transform_x / transform_y)),
		.y = (HEIGHT / 2)
	});
}
