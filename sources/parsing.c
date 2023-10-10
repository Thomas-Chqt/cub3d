/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:55:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/10 13:34:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "error.h"

int	load_cubfile(char *file, t_cubf *cubf)
{
	int	fd;

	*cubf = (t_cubf){0};
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	g_file_err()->file = file;
	g_file_err()->line = 0;
	if (parse_cubf_data(fd, cubf) != 0)
		return (close(fd), -1);
	if (parse_cubf_map(fd, cubf) != 0)
		return (close(fd), free_cub_file(cubf), -1);
	close(fd);
	if (load_textures(cubf) != 0)
		return (free_cub_file(cubf), -1);
	if (check_cubf_map(cubf) != 0)
		return (free_cub_file(cubf), -1);
	return (0);
}

void	free_cub_file(t_cubf *cubf)
{
	int	i;

	free(cubf->no_tex);
	free_context(cubf->no_ctx);
	free(cubf->so_tex);
	free_context(cubf->so_ctx);
	free(cubf->we_tex);
	free_context(cubf->we_ctx);
	free(cubf->ea_tex);
	free_context(cubf->ea_ctx);
	i = 0;
	while (cubf->tiles != NULL && i < cubf->size.y)
		free(cubf->tiles[i++]);
	free(cubf->tiles);
	*cubf = (t_cubf){0};
}
