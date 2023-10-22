/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:44:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 13:16:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "cubfile.h"
#include "inputs.h"
#include "minimap.h"
#include "entity.h"

static void	clean_setup(t_cub3d *cub);

int	setup(t_cub3d *cub, char *file)
{
	if (parse_cubfile(&cub->cubf, file) != 0)
		return (clean_setup(cub), -1);
	if (setup_inputs(cub) != 0)
		return (clean_setup(cub), -1);
	if (create_mmap_ctxs(cub) != 0)
		return (clean_setup(cub), set_error(MALLOC_ERROR), -1);
	if (setup_entities(cub) != 0)
		return (clean_setup(cub), -1);
	return (0);
}

void	loop(t_cub3d *cub)
{
	handle_inputs(cub);
}

void	clean(t_cub3d *cub)
{
	clean_setup(cub);
	delete_window();
}

static void	clean_setup(t_cub3d *cub)
{
	clean_entities(cub);
	clean_mmap_ctxs(cub);
	clean_cubfile(cub->cubf);
}
