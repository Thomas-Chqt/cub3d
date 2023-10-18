/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:58:47 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 15:09:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

t_bool	is_file_over(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && is_empty_str(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL && is_empty_str(line) == false)
		return (free(line), false);
	return (true);
}

t_mtile	**calloc_tiles(t_vec2i size)
{
	t_mtile	**res;
	int		i;

	i = 0;
	res = malloc(size.y * sizeof(t_mtile *));
	if (res == NULL)
		return (NULL);
	while (i < size.y)
	{
		res[i] = ft_calloc(size.x, sizeof(t_mtile *));
		if (res[i] == NULL)
			break ;
		i++;
	}
	if (i == size.y)
		return (res);
	while (i >= 0)
		free(res[i--]);
	free(res);
	return (NULL);
}
