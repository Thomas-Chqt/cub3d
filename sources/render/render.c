/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:41:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 17:31:50 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

static void	draw_wall_line(t_vec2i wall_curr, t_vec2i wall_end,
				int wall_h, float wall_x);

void	render_minimap(t_vec2i pos)
{
	put_context(cub3d()->mmap_ctx, pos);
	put_context(cub3d()->mmap_p_ctx,
		sub_vi2vi2(mtos(cub3d()->p_pos, pos),
			div_vi2vi2(ctx_size(cub3d()->mmap_p_ctx), (t_vec2i){2, 2})));
}
// clear_ctx(cub3d()->ray_ctx);
// for (int x = 0; x < WIDTH; x++)
// {
// 	if (cub3d()->dda_res[x].hit_side == no)
// 	{
// 		draw_line(cub3d()->ray_ctx,
// 			mtos(cub3d()->p_pos, pos),
// 			mtos(add_vf2vf2(cub3d()->p_pos, 
// 				mul_vf2f(cub3d()->dda_res[x].dir, cub3d()->dda_res[x].dist)), pos),
// 			RED);
// 	}
// 	else if (cub3d()->dda_res[x].hit_side == so)
// 	{
// 		draw_line(cub3d()->ray_ctx,
// 			mtos(cub3d()->p_pos, pos),
// 			mtos(add_vf2vf2(cub3d()->p_pos, 
// 				mul_vf2f(cub3d()->dda_res[x].dir, cub3d()->dda_res[x].dist)), pos),
// 			GREEN);
// 	}
// 	else if (cub3d()->dda_res[x].hit_side == ea)
// 	{
// 		draw_line(cub3d()->ray_ctx,
// 			mtos(cub3d()->p_pos, pos),
// 			mtos(add_vf2vf2(cub3d()->p_pos, 
// 				mul_vf2f(cub3d()->dda_res[x].dir, cub3d()->dda_res[x].dist)), pos),
// 			BLUE);
// 	}
// 	else if (cub3d()->dda_res[x].hit_side == we)
// 	{
// 		draw_line(cub3d()->ray_ctx,
// 			mtos(cub3d()->p_pos, pos),
// 			mtos(add_vf2vf2(cub3d()->p_pos, 
// 				mul_vf2f(cub3d()->dda_res[x].dir, cub3d()->dda_res[x].dist)), pos),
// 			BLACK);
// 	}
// }
// put_context(cub3d()->ray_ctx, (t_vec2i){0, 0});

void	render_walls(void)
{
	int		wall_h;
	int		x;
	t_vec2i	wall_start;
	t_vec2i	wall_end;

	x = 0;
	while (x < WIDTH)
	{
		wall_h = (int)(HEIGHT / cub3d()->dda_res[x].dist);
		wall_start = (t_vec2i){x, HEIGHT / 2 - wall_h / 2};
		wall_end = (t_vec2i){x, HEIGHT / 2 + wall_h / 2};
		if (wall_h >= HEIGHT)
		{
			wall_start = (t_vec2i){x, 0};
			wall_end = (t_vec2i){x, HEIGHT};
		}
		draw_line(back_ctx(), (t_vec2i){x, 0}, wall_start, cub3d()->c_color);
		draw_w_line(x, wall_h,
			get_side_tex(cub3d()->dda_res[x].hit_side),
			cub3d()->dda_res[x].wall_x);
		draw_line(back_ctx(), wall_end, (t_vec2i){x, HEIGHT}, cub3d()->c_color);
		x++;
	}
}

static void	draw_wall_line(t_vec2i wall_curr, t_vec2i wall_end,
				int wall_h, float wall_x)
{
	t_vec2f	tex_pos;
	float	tex_step;
}