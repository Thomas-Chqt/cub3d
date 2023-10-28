/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/28 13:49:18 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubfile_internal.h"

int	parse_cubfile(t_cubf **dest, char *file)
{
	t_cubf	*cubf;
	int		fd;

	set_error_cubf(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (set_error(CUBF_OPEN_ERROR), -1);
	cubf = ft_calloc(1, sizeof(t_cubf));
	if (cubf == NULL)
		return (close(fd), set_error(MALLOC_ERROR), -1);
	*cub_error_line() = 0;
	if (load_data(&cubf->data, fd) != 0)
		return (close(fd), free(cubf), -1);
	if (load_map(&cubf->map, fd) != 0)
		return (close(fd), clean_data(&cubf->data), free(cubf), -1);
	close(fd);
	if (check_map(cubf) != 0)
		return (clean_cubfile(cubf), -1);
	*dest = cubf;
	return (0);
}

t_list	*get_entities_srt_pos(t_cubf *cubf)
{
	return (cubf->map.entity_lst);
}

t_mtile	get_mtile(t_cubf *cubf, t_vec2i pos)
{
	if (pos.x < 0 || pos.x >= cubf->map.size.x)
		return (out_map);
	if (pos.y < 0 || pos.y >= cubf->map.size.y)
		return (out_map);
	return (cubf->map.tiles[pos.y][pos.x]);
}

void	toggle_door(t_cubf *cubf, t_vec2i pos)
{
	if (cubf->map.tiles[pos.y][pos.x] == open_door)
		cubf->map.tiles[pos.y][pos.x] = close_door;
	else if (cubf->map.tiles[pos.y][pos.x] == close_door)
		cubf->map.tiles[pos.y][pos.x] = open_door;
}

void	clean_cubfile(t_cubf *cubf)
{
	if (cubf == NULL)
		return ;
	clean_data(&cubf->data);
	clean_map(&cubf->map);
	free(cubf);
}
