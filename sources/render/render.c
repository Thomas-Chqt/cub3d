/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:41:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/15 20:36:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
# include "sprite.h"

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
	t_vec2i	curr;
	t_wall	wall_data;

	curr.x = 0;
	while (curr.x < WIDTH)
	{
		wall_data = init_wall_data(cub3d()->dda_res[curr.x]);
		curr.y = 0;
		while (curr.y < HEIGHT)
		{
			if (curr.y < wall_data.wall_srt)
				draw_pixel(back_ctx(), curr, cub3d()->c_color);
			else if (curr.y < wall_data.wall_end)
				draw_pixel(back_ctx(), curr, tex_px(wall_data, curr));
			else
				draw_pixel(back_ctx(), curr, cub3d()->f_color);
			curr.y++;
		}
		curr.x++;
	}
}

void	render_sprites(void)
{
	ft_lstiter(cub3d()->sprite_lst, (void (*)(void *))&render_sprite);
}

void	render_sprite(t_sprite *sp)
{
	float	sp_dist;
	t_vec2i	sp_screen_pos = sprite_to_screen(sp, &sp_dist);


	if (!(sp_dist > 0))
		return ;


	int spriteWidth		= ft_abs((int)(HEIGHT / (sp_dist)));
	int spriteHeight	= ft_abs((int)(HEIGHT / (sp_dist)));

	t_vec2i screen_start = {
		.x = sp_screen_pos.x - (spriteWidth / 2),
		.y = (HEIGHT / 2) - (spriteHeight / 2)
	};
	
	t_vec2f img_step = (t_vec2f){
		.x = (float)ctx_size(sp->img).x / (float)spriteWidth,
		.y = (float)ctx_size(sp->img).y / (float)spriteHeight
	};


	t_vec2i	screen_curr;
	t_vec2f img_curr;
	screen_curr.x = screen_start.x;
	if (screen_curr.x < 0)
		screen_curr.x = 0;
	img_curr.x = (screen_curr.x - screen_start.x) * img_step.x;
	while (screen_curr.x < WIDTH && screen_curr.x < screen_start.x + spriteWidth)
	{
		if (sp_dist < cub3d()->dda_res[screen_curr.x].dist)
		{
			screen_curr.y = screen_start.y;
			if (screen_curr.y < 0)
				screen_curr.y = 0;
			img_curr.y = (screen_curr.y - screen_start.y) * img_step.y;
			while (screen_curr.y < HEIGHT && screen_curr.y < screen_start.y + spriteHeight)
			{
				if (ctx_px(sp->img, vf2tovi2(img_curr)) != 0)
					draw_pixel(back_ctx(), screen_curr, ctx_px(sp->img, vf2tovi2(img_curr)));
				screen_curr.y++;
				img_curr.y += img_step.y;
			}
		}
		screen_curr.x++;
		img_curr.x += img_step.x;
	}
}
