/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:16:13 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/10 15:49:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2f	tile_to_vect_dir(t_tile tile)
{
	if (tile == pno)
		return ((t_vec2f){.x = 0.0f, .y = -1.0f});
	if (tile == pso)
		return ((t_vec2f){.x = 0.0f, .y = 1.0f});
	if (tile == pea)
		return ((t_vec2f){.x = 1.0f, .y = 0.0f});
	if (tile == pwe)
		return ((t_vec2f){.x = -1.0f, .y = 0.0f});
	return ((t_vec2f){.x = 0.0f, .y = 0.0f});
}

t_vec2f	tile_to_vect_plane(t_tile tile)
{
	if (tile == pno)
		return ((t_vec2f){.x = tanf(torad((float)FOV / 2.0f)), .y = 0.0f});
	if (tile == pso)
		return ((t_vec2f){.x = -tanf(torad((float)FOV / 2.0f)), .y = 0.0f});
	if (tile == pea)
		return ((t_vec2f){.x = 0.0f, .y = tanf(torad((float)FOV / 2))});
	if (tile == pwe)
		return ((t_vec2f){.x = 0.0f, .y = -tanf(torad((float)FOV / 2))});
	return ((t_vec2f){.x = 0.0f, .y = 0.0f});
}

t_bool	is_in_wall(t_vec2f p_pos)
{
	t_vec2f	p_size;
	t_vec2f	t_l;
	t_vec2f	t_r;
	t_vec2f	b_l;
	t_vec2f	b_r;

	p_size = div_vf2vf2(vi2tovf2(ctx_size(cub3d()->mmap.p_ctx)),
			vi2tovf2(tile_size_px()));
	t_l = (t_vec2f){p_pos.x - (p_size.x / 2), p_pos.y - (p_size.y / 2)};
	t_r = (t_vec2f){p_pos.x + (p_size.x / 2), p_pos.y - (p_size.y / 2)};
	b_l = (t_vec2f){p_pos.x - (p_size.x / 2), p_pos.y + (p_size.y / 2)};
	b_r = (t_vec2f){p_pos.x + (p_size.x / 2), p_pos.y + (p_size.y / 2)};
	if (cub3d()->cubf.tiles[(int)(t_l.y)][(int)t_l.x] < ins)
		return (true);
	if (cub3d()->cubf.tiles[(int)t_r.y][(int)t_r.x] < ins)
		return (true);
	if (cub3d()->cubf.tiles[(int)b_l.y][(int)b_l.x] < ins)
		return (true);
	if (cub3d()->cubf.tiles[(int)b_r.y][(int)b_r.x] < ins)
		return (true);
	return (false);
}
