/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:55:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/05 14:46:10 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "error.h"

int	load_cubfile(char *file, t_cubf *cubf)
{
	int	fd;

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
	return (0);
}

void	free_cub_file(t_cubf *cubf)
{
	int	i;

	free(cubf->no_tex);
	free(cubf->so_tex);
	free(cubf->we_tex);
	free(cubf->ea_tex);
	i = 0;
	while (cubf->tiles != NULL && i < cubf->size.h)
		free(cubf->tiles[i++]);
	free(cubf->tiles);
}
