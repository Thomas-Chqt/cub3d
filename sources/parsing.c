/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:55:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/03 18:00:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	if (check_map(&cub) != 0)
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
	free(cub.tiles);
}

t_tile	*get_tile(t_cubfile cub, t_pos pos)
{
	return (cub.tiles + (cub.width * pos.y + pos.x));
}
