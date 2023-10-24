/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:16:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 19:54:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_internal.h"

static void	cast_wall_ray(t_wray_res *res, t_dda_data ddata, t_cubf *cubf);
static void	cast_ent_ray(t_eray_res *res, t_dda_data da, t_list *ents,
				t_cubf *cub);

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

t_ent	*entity_ray(t_ent *src, t_vec2f dir, t_list *ent_list, t_cubf *cub)
{
	t_eray_res	res;
	t_dda_data	ddata;

	res = (t_eray_res){};
	ddata = make_dda_data(ent_pos(src), dir, NULL);
	ddata.ent_src = src;
	cast_ent_ray(&res, ddata, ent_list, cub);
	return (res.hit);
}

static void	cast_wall_ray(t_wray_res *res, t_dda_data da, t_cubf *cubf)
{
	while (!is_wall_hit(res, &da, cubf))
	{
		if (da.lcurr.x < da.lcurr.y)
		{
			res->len = da.lcurr.x;
			da.lcurr.x += da.lstep.x;
			da.tcurr.x += da.tstep.x;
			da.hit_side = 1;
			da.wall_x = da.srt.y + res->len * da.dir.y;
		}
		else
		{
			res->len = da.lcurr.y;
			da.lcurr.y += da.lstep.y;
			da.tcurr.y += da.tstep.y;
			da.hit_side = 0;
			da.wall_x = da.srt.x + res->len * da.dir.x;
		}
	}
	da.wall_x -= floor(da.wall_x);
	if ((da.hit_side && da.dir.x < 0) || (!da.hit_side && da.dir.y > 0))
		res->vstripe = ctx_vstripe(da.c_tex, ctx_size(da.c_tex).x
				- (da.wall_x * ctx_size(da.c_tex).x) - 1);
	res->vstripe = ctx_vstripe(da.c_tex, da.wall_x * ctx_size(da.c_tex).x);
}

static void	cast_ent_ray(t_eray_res *res, t_dda_data da, t_list *ents,
				t_cubf *cub)
{
	while (!is_ent_hit(res, &da, ents) && get_mtile(cub, da.tcurr) < 0
		&& res->len < 50)
	{
		if (da.lcurr.x < da.lcurr.y)
		{
			res->len = da.lcurr.x;
			da.lcurr.x += da.lstep.x;
			da.tcurr.x += da.tstep.x;
		}
		else
		{
			res->len = da.lcurr.y;
			da.lcurr.y += da.lstep.y;
			da.tcurr.y += da.tstep.y;
		}
	}
}
