/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:12:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/10 15:49:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

static void	draw_c_line(int x, int wall_h);
static void	draw_w_line(int x, int wall_h, t_ctx *tex, float wall_x);
static void	draw_f_line(int x, int wall_h);

void	render_minimap(void)
{
	put_context(cub3d()->mmap.ctx, cub3d()->mmap.pos);
	put_context(cub3d()->mmap.p_ctx, sub_vi2vi2(mtos(cub3d()->player.pos),
			div_vi2vi2(ctx_size(cub3d()->mmap.p_ctx), (t_vec2i){2, 2})));
}

void	render_walls(void)
{
	int	wall_h;
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		wall_h = (int)(HEIGHT / cub3d()->dda_res[x].dist);
		draw_c_line(x, wall_h);
		draw_w_line(
			x,
			wall_h,
			get_side_tex(cub3d()->dda_res[x].hit_side),
			cub3d()->dda_res[x].wall_x);
		draw_f_line(x, wall_h);
	}
	put_context(cub3d()->wall_ctx, (t_vec2i){0, 0});
}

static void	draw_c_line(int x, int wall_h)
{
	int	y_end;

	if (wall_h >= HEIGHT)
		return ;
	y_end = HEIGHT / 2 - wall_h / 2;
	draw_line(cub3d()->wall_ctx,
		(t_vec2i){x, 0},
		(t_vec2i){x, y_end},
		cub3d()->cubf.c_col);
}

static void	draw_w_line(int x, int wall_h, t_ctx *tex, float wall_x)
{
	t_vec2i	screen_pos;
	int		end_screen_y;
	float	tex_step;
	t_vec2f	tex_pos;

	screen_pos = (t_vec2i){x, (HEIGHT / 2 - wall_h / 2) - 1};
	end_screen_y = HEIGHT / 2 + wall_h / 2;
	if (wall_h >= HEIGHT)
	{
		screen_pos = (t_vec2i){x, -1};
		end_screen_y = HEIGHT;
	}
	tex_step = (float)ctx_size(tex).y / (float)wall_h;
	tex_pos = (t_vec2f){
		wall_x * (float)ctx_size(tex).x,
		(screen_pos.y - (HEIGHT / 2 - wall_h / 2)) * tex_step
	};
	if (tex == cub3d()->cubf.we_ctx || tex == cub3d()->cubf.so_ctx)
		tex_pos.x = (float)ctx_size(tex).x - tex_pos.x -1;
	while (++screen_pos.y < end_screen_y)
	{
		draw_pixel(cub3d()->wall_ctx, screen_pos,
			ctx_px(tex, vf2tovi2(tex_pos)));
		tex_pos.y += tex_step;
	}
}

static void	draw_f_line(int x, int wall_h)
{
	int	y_start;

	if (wall_h >= HEIGHT)
		return ;
	y_start = HEIGHT / 2 + wall_h / 2;
	draw_line(cub3d()->wall_ctx,
		(t_vec2i){x, y_start},
		(t_vec2i){x, HEIGHT},
		cub3d()->cubf.f_col);
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
