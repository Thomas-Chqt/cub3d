/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:42:44 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 14:46:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "minimap.h"

t_vec2i	mtos(t_vec2f vect, t_vec2i mmap_pos)
{
	return (
		vf2tovi2(
			add_vf2vi2 (
				mul_vf2vi2(
					vect,
					mmap_tile_pxsize()
				),
				mmap_pos
			)
		)
	);
}
