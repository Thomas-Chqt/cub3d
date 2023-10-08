/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:49:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/08 16:13:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"

void	init_player(void)
{
	set_ppos(add_vf2vf2(vi2tovf2(cub3d()->cubf.p_start), (t_vec2f){0.5, 0.5}));
	cub3d()->player.dir = tile_to_vect_dir(cub3d()->cubf.p_start_rot);
	cub3d()->player.plane = tile_to_vect_plane(cub3d()->cubf.p_start_rot);
}

