/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:04:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 13:23:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

static t_wh	get_tile_size(t_stpdata *stpdata, t_wh size);

int	make_minimap(t_stpdata *stpdata, t_wh size)
{
	t_wh	tile_size;
	t_pos	curr;

	stpdata->minimap_ctx = new_context(size);
	if (stpdata->minimap_ctx == NULL)
		return (set_error(MALLOC_ERROR), -1);
	tile_size = get_tile_size(stpdata, size);
	curr.y = 0;
	while (curr.y < stpdata->cub.size.h)
	{
		curr.x = 0;
		while (curr.x < stpdata->cub.size.w)
		{
			if (stpdata->cub.tiles[curr.y][curr.x] > wal)
				put_rect(stpdata->minimap_ctx, tile_size,
					mulposwh(curr, tile_size), WHITE);
			else if (stpdata->cub.tiles[curr.y][curr.x] == wal)
				put_rect(stpdata->minimap_ctx, tile_size,
					mulposwh(curr, tile_size), BLACK);
			curr.x++;
		}
		curr.y++;
	}
	return (0);
}

static t_wh	get_tile_size(t_stpdata *stpdata, t_wh size)
{
	float	r_w;
	float	r_h;

	r_w = (float)size.w / (float)stpdata->cub.size.w;
	r_h = (float)size.h / (float)stpdata->cub.size.h;
	if (r_w < r_h)
		return ((t_wh){r_w, r_w});
	else
		return ((t_wh){r_h, r_h});
}
