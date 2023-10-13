/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:41:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 22:48:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	render_minimap(t_vec2i pos)
{
	int	x;

	put_context(cub3d()->mmap_ctx, pos);
	put_context(cub3d()->mmap_p_ctx,
		sub_vi2vi2(mtos(cub3d()->p_pos, pos),
			div_vi2vi2(ctx_size(cub3d()->mmap_p_ctx), (t_vec2i){2, 2})));
	clear_ctx(cub3d()->rays_ctx);
	x = 0;
	while (x < WIDTH)
	{
		draw_line(cub3d()->rays_ctx, mtos(cub3d()->p_pos, pos),
			mtos(add_vf2vf2(cub3d()->p_pos, mul_vf2f(cub3d()->dda_res[x].dir,
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
