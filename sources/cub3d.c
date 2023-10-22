/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:44:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 19:37:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "cubfile.h"
#include "inputs.h"
#include "minimap.h"
#include "entity.h"
#include "dda.h"

static int	setup_ctxs(t_cub3d *cub);
static void	clean_setup(t_cub3d *cub);

int	setup(t_cub3d *cub, char *file)
{
	if (setup_ctxs(cub) != 0)
		return (clean_setup(cub), set_error(MALLOC_ERROR), -1);
	draw_mmap_overlay(cub->mmap_overlay);
	if (parse_cubfile(&cub->cubf, file) != 0)
		return (clean_setup(cub), -1);
	if (setup_inputs(cub) != 0)
		return (clean_setup(cub), -1);
	if (setup_entities(cub) != 0)
		return (clean_setup(cub), -1);
	return (0);
}

static int	setup_ctxs(t_cub3d *cub)
{
	cub->mmap_back = new_context((t_vec2i){200, 200});
	cub->mmap_overlay = new_context((t_vec2i){200, 200});
	cub->wall_ctx = new_context((t_vec2i){WIDTH, HEIGHT});
	if (cub->mmap_back == NULL || cub->mmap_overlay == NULL
		|| cub->wall_ctx == NULL)
	{
		free_context(cub->mmap_back);
		cub->mmap_back = NULL;
		free_context(cub->mmap_overlay);
		cub->mmap_overlay = NULL;
		free_context(cub->wall_ctx);
		cub->wall_ctx = NULL;
		return (-1);
	}
	return (0);
}

void	loop(t_cub3d *cub)
{
	handle_inputs(cub);
	draw_walls(cub->wall_ctx, cub->p_ref, cub->cubf, cub->wall_dist);
	put_context(cub->wall_ctx, (t_vec2i){0, 0});
	draw_mmap(cub->mmap_back, cub->cubf, cub->p_ref);
	put_context(cub->mmap_back, (t_vec2i){10, 10});
	put_context(cub->mmap_overlay, (t_vec2i){10, 10});
}

void	clean(t_cub3d *cub)
{
	clean_setup(cub);
	delete_window();
}

static void	clean_setup(t_cub3d *cub)
{
	clean_entities(cub);
	clean_cubfile(cub->cubf);
	free_context(cub->mmap_back);
	cub->mmap_back = NULL;
	free_context(cub->mmap_overlay);
	cub->mmap_overlay = NULL;
	free_context(cub->wall_ctx);
	cub->wall_ctx = NULL;
}
