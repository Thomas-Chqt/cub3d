/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:13:32 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/08 15:28:59 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

t_vec2i	mtos(t_vec2f vect)
{
	return (
		vf2tovi2(
			add_vf2vi2 (
				mul_vf2vi2(
					vect,
					tile_size_px()
				),
				cub3d()->mmap.pos
			)
		)
	);
}
