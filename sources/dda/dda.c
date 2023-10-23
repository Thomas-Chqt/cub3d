/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:16:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/23 11:08:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_internal.h"

static void	cast_wall_ray(t_wray_res *res, t_dda_data ddata, t_cubf *cub);

void	render_walls(t_ent *pl, t_cubf *cubf, float *dist_ret)
{
	t_wray_res	res;
	t_vec2f		ray_dir;
	int			x;

	x = 0;
	while (x < WIDTH)
	{
		ray_dir = add_vf2vf2(ent_dir(pl), mul_vf2f(ent_pla(pl),
					2 * (float)x / (float)WIDTH - 1));
		cast_wall_ray(&res, make_dda_data(ent_pos(pl), ray_dir, cubf), cubf);
		if (HEIGHT / 2 - (int)(HEIGHT / res.len) / 2 > 0)
			draw_line(back_ctx(), (t_vec2i){x, 0},
				(t_vec2i){x, HEIGHT / 2 - (int)(HEIGHT / res.len) / 2},
				get_c_color(cubf));
		draw_vstripe(back_ctx(), res.vstripe,
			(t_vec2i){x, HEIGHT / 2 - (int)(HEIGHT / res.len) / 2},
			(t_vec2i){x, HEIGHT / 2 + (int)(HEIGHT / res.len) / 2});
		if (HEIGHT / 2 + (int)(HEIGHT / res.len) / 2 < HEIGHT)
			draw_line(back_ctx(),
				(t_vec2i){x, HEIGHT / 2 + (int)(HEIGHT / res.len) / 2},
				(t_vec2i){x, HEIGHT}, get_f_color(cubf));
		dist_ret[x] = res.len;
		x++;
	}
}

static void	cast_wall_ray(t_wray_res *res, t_dda_data da, t_cubf *cub)
{
	while (!is_out_map(cub, da.tcurr) && !is_solid(cub, da.tcurr))
	{
		if (da.lcurr.x < da.lcurr.y)
		{
			res->len = da.lcurr.x;
			da.lcurr.x += da.lstep.x;
			da.tcurr.x += da.tstep.x;
			da.c_tex = da.v_tex;
			da.wall_x = da.srt.y + res->len * da.dir.y;
		}
		else
		{
			res->len = da.lcurr.y;
			da.lcurr.y += da.lstep.y;
			da.tcurr.y += da.tstep.y;
			da.c_tex = da.h_tex;
			da.wall_x = da.srt.x + res->len * da.dir.x;
		}
	}
	da.wall_x -= floor(da.wall_x);
	if ((da.c_tex == da.v_tex && da.dir.x < 0)
		|| (da.c_tex == da.h_tex && da.dir.y > 0))
		res->vstripe = ctx_vstripe(da.c_tex, ctx_size(da.c_tex).x
				- (da.wall_x * ctx_size(da.c_tex).x) - 1);
	res->vstripe = ctx_vstripe(da.c_tex, da.wall_x * ctx_size(da.c_tex).x);
}
