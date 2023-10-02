/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:55:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/02 21:58:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parse_data(int fd, t_cubfile *cub);
static int	parse_next_data(int fd, t_cubfile *cub);

t_cubfile	load_cubfile(char *file)
{
	t_cubfile	cub;
	int			fd;

	cub = (t_cubfile){};
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (cub_perror(file), (t_cubfile){});
	cub_file_err()->file = file;
	if (parse_data(fd, &cub) != 0)
		return (close(fd), free_cubfile(cub), (t_cubfile){});
	if (parse_map(fd, &cub) != 0)
		return (close(fd), free_cubfile(cub), (t_cubfile){});
	close(fd);
	if (check_map(cub) != 0)
		return (free_cubfile(cub), (t_cubfile){});
	return (cub);
}

void	free_cubfile(t_cubfile cub)
{
	t_uint64	i;

	free(cub.no_tex);
	free(cub.so_tex);
	free(cub.we_tex);
	free(cub.ea_tex);
	if (cub.height > 0)
	{
		i = 0;
		while (i < cub.height)
			free(cub.tiles[i]);
		free(cub.tiles);
	}
}

