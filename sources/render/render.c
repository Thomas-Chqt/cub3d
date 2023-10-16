/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:41:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/16 18:56:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "sprite.h"

void	render_sprite(t_sprite *sp);

void	render_minimap(t_vec2i pos)
{
	int	x;

	put_context(cub3d()->mmap_ctx, pos);
	put_context(cub3d()->mmap_p_ctx,
		sub_vi2vi2(mtomm(cub3d()->p_pos, pos),
			div_vi2vi2(ctx_size(cub3d()->mmap_p_ctx), (t_vec2i){2, 2})));
	clear_ctx(cub3d()->rays_ctx);
	x = 0;
	while (x < WIDTH)
	{
		draw_line(cub3d()->rays_ctx, mtomm(cub3d()->p_pos, pos),
			mtomm(add_vf2vf2(cub3d()->p_pos, mul_vf2f(cub3d()->dda_res[x].dir,
						cub3d()->dda_res[x].dist)), pos), RED);
		x++;
	}
	put_context(cub3d()->rays_ctx, pos);
}

void	render_walls(void)
{
	int		x;
	t_wall	wall_data;

	x = 0;
	while (x < WIDTH)
	{
		wall_data = init_wall_data(cub3d()->dda_res[x]);
		if (wall_data.wall_srt > 0)
			draw_line(back_ctx(), (t_vec2i){x, 0},
				(t_vec2i){x, wall_data.wall_srt - 1}, cub3d()->c_color);
		draw_vstripe(back_ctx(), wall_data.stripe,
			(t_vec2i){x, wall_data.wall_srt}, (t_vec2i){x, wall_data.wall_end});
		if (wall_data.wall_end < HEIGHT)
			draw_line(back_ctx(), (t_vec2i){x, wall_data.wall_end},
				(t_vec2i){x, HEIGHT - 1}, cub3d()->f_color);
		x++;
	}
}

void	render_sprites(void)
{
	ft_lstiter(cub3d()->sprite_lst, (void (*)(void *)) & render_sprite);
}

void	render_sprite(t_sprite *sp)
{
	float	sp_dist;
	t_vec2i	sp_screen_pos;
	t_vec2i	sp_size;
	int		x;
	float	tex_x;

	sp_screen_pos = transform_sppos(sp, &sp_dist);
	if (sp_dist <= 0)
		return ;
	sp_size = (t_vec2i){.x = ft_abs((int)(HEIGHT / (sp_dist))),
		.y = ft_abs((int)(HEIGHT / (sp_dist)))};
	x = sp_screen_pos.x - (sp_size.x / 2);
	tex_x = 0;
	while (x < WIDTH && x < sp_screen_pos.x + (sp_size.x / 2))
	{
		if (x > 0 && sp_dist < cub3d()->dda_res[x].dist)
		{
			draw_vstripe(back_ctx(), ctx_vstripe(sp->img, (int)tex_x),
				(t_vec2i){x, sp_screen_pos.y - (sp_size.y / 2)},
				(t_vec2i){x, sp_screen_pos.y + (sp_size.y / 2)});
		}
		x++;
		tex_x += (float)ctx_size(sp->img).x / (float)sp_size.x;
	}
}
