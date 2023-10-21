/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 21:20:55 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubfile_internal.h"

int	parse_cubfile(t_cubf **dest, char *file)
{
	t_cubf	*cubf;
	int		fd;

	ft_strlcpy(cub_error()->cubf, file, ERROR_FILES_MAX_LEN);
	if (ft_strrchr(file, '.') == NULL
		|| str_cmp(ft_strrchr(file, '.'), ".cub") != 0)
		return (set_error(BAD_ARGS_ERROR), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (set_error(CUBF_OPEN_ERROR), -1);
	cubf = ft_calloc(1, sizeof(t_cubf));
	if (cubf == NULL)
		return (set_error(MALLOC_ERROR), -1);
	cub_error()->line = 0;
	if (load_data(&cubf->data, fd) != 0)
		return (free(cubf), -1);
	if (load_map(&cubf->map, fd) != 0)
		return (clean_data(&cubf->data), free(cubf), -1);
	close(fd);
	if (check_map(cubf) != 0)
		return (clean_cubfile(cubf), -1);
	*dest = cubf;
	return (0);
}

t_bool	is_out_map(t_cubf *cubf, t_vec2i pos)
{
	if (pos.x < 0 || pos.y < 0)
		return (true);
	if (pos.x >= cubf->map.size.x || pos.y >= cubf->map.size.y)
		return (true);
	if (cubf->map.tiles[pos.y][pos.x] == 0)
		return (true);
	return (false);
}

t_bool	is_solid(t_cubf *cubf, t_vec2i pos)
{
	if (pos.x < 0 || pos.y < 0)
		return (false);
	if (pos.x >= cubf->map.size.x || pos.y >= cubf->map.size.y)
		return (false);
	if (cubf->map.tiles[pos.y][pos.x] < wall)
		return (false);
	return (true);
}

void	clean_cubfile(t_cubf *cubf)
{
	if (cubf == NULL)
		return ;
	clean_data(&cubf->data);
	clean_map(&cubf->map);
	free(cubf);
}
