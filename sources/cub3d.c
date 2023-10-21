/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:44:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 21:23:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "cubfile.h"
#include "inputs.h"
#include "minimap.h"

static void clean_setup(t_cub3d *cub);

int	setup(t_cub3d *cub, char *argv[])
{
	parse_cubfile(&cub->cubf, argv[1]);
	setup_inputs(cub);
	create_mmap_ctxs(cub);
	return (0);
}

void	loop(t_cub3d *cub)
{
	handle_inputs(cub);
}

void	clean(t_cub3d *cub)
{
	delete_window();
}

static void clean_setup(t_cub3d *cub)
{
	clean_mmap_ctxs(cub);
	clean_cubfile(cub->cubf);
}
