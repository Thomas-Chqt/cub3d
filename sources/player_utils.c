/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:16:13 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 19:45:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect2d	tile_to_vect_dir(t_tile tile)
{
	if (tile == pno)
		return ((t_vect2d){.x = 0.0f, .y = -1.0f});
	if (tile == pso)
		return ((t_vect2d){.x = 0.0f, .y = 1.0f});
	if (tile == pea)
		return ((t_vect2d){.x = 1.0f, .y = 0.0f});
	if (tile == pwe)
		return ((t_vect2d){.x = -1.0f, .y = 0.0f});
	return ((t_vect2d){.x = 0.0f, .y = 0.0f});
}

t_vect2d	tile_to_vect_plane(t_tile tile)
{
	if (tile == pno)
		return ((t_vect2d){.x = tanf(torad((float)FOV / 2.0f)), .y = 0.0f});
	if (tile == pso)
		return ((t_vect2d){.x = -tanf(torad((float)FOV / 2.0f)), .y = 0.0f});
	if (tile == pea)
		return ((t_vect2d){.x = 0.0f, .y = tanf(torad((float)FOV / 2))});
	if (tile == pwe)
		return ((t_vect2d){.x = 0.0f, .y = -tanf(torad((float)FOV / 2))});
	return ((t_vect2d){.x = 0.0f, .y = 0.0f});
}
