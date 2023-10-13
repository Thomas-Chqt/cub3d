/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:14:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 16:16:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"
#include "minimap.h"

t_bool	is_in_wall(t_vec2f p_pos)
{
	t_vec2f	p_size;
	t_vec2f	t_l;
	t_vec2f	t_r;
	t_vec2f	b_l;
	t_vec2f	b_r;

	p_size = div_vf2vf2(vi2tovf2(ctx_size(cub3d()->mmap_p_ctx)),
			vi2tovf2(mmap_tile_pxsize()));
	t_l = (t_vec2f){p_pos.x - (p_size.x / 2), p_pos.y - (p_size.y / 2)};
	t_r = (t_vec2f){p_pos.x + (p_size.x / 2), p_pos.y - (p_size.y / 2)};
	b_l = (t_vec2f){p_pos.x - (p_size.x / 2), p_pos.y + (p_size.y / 2)};
	b_r = (t_vec2f){p_pos.x + (p_size.x / 2), p_pos.y + (p_size.y / 2)};
	if (cub3d()->map[(int)(t_l.y)][(int)t_l.x] >= wall)
		return (true);
	if (cub3d()->map[(int)t_r.y][(int)t_r.x] >= wall)
		return (true);
	if (cub3d()->map[(int)b_l.y][(int)b_l.x] >= wall)
		return (true);
	if (cub3d()->map[(int)b_r.y][(int)b_r.x] >= wall)
		return (true);
	return (false);
}
