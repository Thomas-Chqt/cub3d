/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:31:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 18:20:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minimap.h"
#include "error.h"

int	setup_minimap(t_mmap **dest)
{
	t_mmap	*mmap;

	mmap = ft_calloc(1, sizeof(t_mmap));
	if (mmap == NULL)
		return (set_error(MALLOC_ERROR), -1);
	mmap->ctx = new_context((t_vec2i){MMAP_WIDTH, MMAP_HEIGHT});
	if (mmap->ctx == NULL)
		return (free(mmap), set_error(MALLOC_ERROR), -1);
	mmap->overlay_ctx = new_context((t_vec2i){MMAP_WIDTH, MMAP_HEIGHT});
	if (mmap->overlay_ctx == NULL)
		return (clean_minimap(mmap), set_error(MALLOC_ERROR), -1);
	draw_rect(mmap->overlay_ctx, (t_vec2i){MMAP_WIDTH / 2 - MMAP_PSIZE / 2,
		MMAP_HEIGHT / 2 - MMAP_PSIZE / 2},
		(t_vec2i){MMAP_PSIZE, MMAP_PSIZE}, RED);
	*dest = mmap;
	return (0);
}

void	clean_minimap(t_mmap *mmap)
{
	if (mmap == NULL)
		return ;
	free_context(mmap->ctx);
	free_context(mmap->overlay_ctx);
	free(mmap);
}
