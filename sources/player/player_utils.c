/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:14:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 15:59:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"
#include "cubfile.h"

t_vec2f	char_to_dir_vec(char c)
{
	if (c == 'N')
		return ((t_vec2f){.x = 0.0f, .y = -1.0f});
	if (c == 'S')
		return ((t_vec2f){.x = 0.0f, .y = 1.0f});
	if (c == 'E')
		return ((t_vec2f){.x = 1.0f, .y = 0.0f});
	if (c == 'W')
		return ((t_vec2f){.x = -1.0f, .y = 0.0f});
	return ((t_vec2f){0, 0});
}

t_vec2f	char_to_plane_vec(char c)
{
	if (c == 'N')
		return ((t_vec2f){.x = tanf(torad((float)FOV / 2.0f)), .y = 0.0f});
	if (c == 'S')
		return ((t_vec2f){.x = -tanf(torad((float)FOV / 2.0f)), .y = 0.0f});
	if (c == 'E')
		return ((t_vec2f){.x = 0.0f, .y = tanf(torad((float)FOV / 2))});
	if (c == 'W')
		return ((t_vec2f){.x = 0.0f, .y = -tanf(torad((float)FOV / 2))});
	return ((t_vec2f){0, 0});
}

t_bool	is_in_wall(t_play *play, t_vec2f pos, t_cubf *cubf)
{
	t_vec2f	t_l;
	t_vec2f	t_r;
	t_vec2f	b_l;
	t_vec2f	b_r;

	t_l = (t_vec2f){pos.x - (play->hitb.x / 2), pos.y - (play->hitb.y / 2)};
	t_r = (t_vec2f){pos.x + (play->hitb.x / 2), pos.y - (play->hitb.y / 2)};
	b_l = (t_vec2f){pos.x - (play->hitb.x / 2), pos.y + (play->hitb.y / 2)};
	b_r = (t_vec2f){pos.x + (play->hitb.x / 2), pos.y + (play->hitb.y / 2)};
	if (cubf->map[(int)(t_l.y)][(int)t_l.x] >= wall)
		return (true);
	if (cubf->map[(int)t_r.y][(int)t_r.x] >= wall)
		return (true);
	if (cubf->map[(int)b_l.y][(int)b_l.x] >= wall)
		return (true);
	if (cubf->map[(int)b_r.y][(int)b_r.x] >= wall)
		return (true);
	return (false);
}
