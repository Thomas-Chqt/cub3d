/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:28:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 14:30:49 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"

t_vec2i	mmap_tile_pxsize(void)
{
	static t_vec2i	tile_size = {-1, -1};
	t_vec2f			ratio;

	if (tile_size.x == -1 && tile_size.y == -1)
	{
		ratio.x = (float)ctx_size(cub3d()->mmap_ctx).x
			/ (float)cub3d()->m_size.x;
		ratio.y = (float)ctx_size(cub3d()->mmap_ctx).y
			/ (float)cub3d()->m_size.y;
		if (ratio.x < ratio.y)
			tile_size = (t_vec2i){(int)ratio.x, (int)ratio.x};
		else
			tile_size = (t_vec2i){(int)ratio.y, (int)ratio.y};
	}
	return (tile_size);
}
