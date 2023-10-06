/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:49:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 19:28:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"

void	init_player(t_stpdata *stpdata)
{
	set_ppos(stpdata, addvect2df(tovect2d(stpdata->cubf.p_start), 0.5));
	stpdata->play.dir = tile_to_vect_dir(stpdata->cubf.p_start_rot);
	stpdata->play.plane = tile_to_vect_plane(stpdata->cubf.p_start_rot);
}

