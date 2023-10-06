/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:58:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 20:34:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

t_pos	to_screen_coord(t_vect2d vect, t_minimap *mmap)
{
	return (
		topos(
			addvect2dpos (
				mulvect2dwh(
					vect,
					mmap->ti_size
				),
				mmap->pos
			)
		)
	);
}
