/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:16:13 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/08 16:09:08 by tchoquet         ###   ########.fr       */
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
