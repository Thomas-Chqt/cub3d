/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:50:58 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/09 22:12:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_uint32	get_color(t_side side);

void	draw_walls(void)
{
	int			line_h;
	t_vec2i		line[2];
	int			x;

	x = -1;
	while (++x < WIDTH)
	{
		line_h = (int)(HEIGHT / cub3d()->dda_res[x].dist);
		if (line_h > HEIGHT)
			line_h = HEIGHT;
		line[0] = (t_vec2i){.x = x, .y = (HEIGHT / 2) - (line_h / 2)};
		line[1] = (t_vec2i){.x = x, .y = (HEIGHT / 2) + (line_h / 2)};
		draw_line(cub3d()->wall_ctx, (t_vec2i){x, 0}, line[0],
			cub3d()->cubf.c_col);
		draw_line(cub3d()->wall_ctx, line[0], line[1],
			get_color(cub3d()->dda_res[x].hit_side));
		draw_line(cub3d()->wall_ctx, line[1], (t_vec2i){x, HEIGHT},
			cub3d()->cubf.f_col);
	}
	put_context(cub3d()->wall_ctx, (t_vec2i){0, 0});
}

t_uint32	get_color(t_side side)
{
	if (side == no)
		return (RED);
	if (side == so)
		return (GREEN);
	if (side == ea)
		return (0xD00000);
	if (side == we)
		return (0x00D000);
	return (0);
}
