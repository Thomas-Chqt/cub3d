/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:35:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 21:33:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

int	create_mmap_ctxs(t_cub3d *cub)
{
	cub->mmap_back = new_context((t_vec2i){MMAP_WIDTH, MMAP_HEIGHT});
	if (cub->mmap_back == NULL)
		return (-1);
	cub->mmap_overlay = new_context((t_vec2i){MMAP_WIDTH, MMAP_HEIGHT});
	if (cub->mmap_overlay == NULL)
		return (clean_mmap_ctxs(cub), -1);
	draw_rect(cub->mmap_overlay, (t_vec2i){
		MMAP_WIDTH / 2 - MMAP_PSIZE / 2,
		MMAP_HEIGHT / 2 - MMAP_PSIZE / 2},
		(t_vec2i){MMAP_PSIZE, MMAP_PSIZE}, RED);
	return (0);
}

void	clean_mmap_ctxs(t_cub3d *cub)
{
	free_context(cub->mmap_back);
	cub->mmap_back = NULL;
	free_context(cub->mmap_overlay);
	cub->mmap_overlay = NULL;
}
