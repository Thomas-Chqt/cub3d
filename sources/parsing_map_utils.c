/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:18:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/08 14:31:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "error.h"

void	skip_empty_lines(int fd, char **line)
{
	g_file_err()->line++;
	*line = get_next_line(fd);
	while (*line != NULL && is_empty_str(*line))
	{
		free(*line);
		g_file_err()->line++;
		*line = get_next_line(fd);
	}
}

int	normalize_map_line(char **line_ptr)
{
	int	i;

	i = 0;
	while ((*line_ptr)[i] != '\0' && (*line_ptr)[i] != '\n')
	{
		if (ft_strchr(" 01NSEW", (*line_ptr)[i]) == NULL)
			return (set_error(WRONG_CHAR_ERROR), -1);
		i++;
		if (i == INT_MAX && (*line_ptr)[i] != '\0' && (*line_ptr)[i] != '\n')
			return (set_error(LONG_LINE_ERROR), -1);
	}
	(*line_ptr)[i] = '\0';
	return (0);
}

t_tile	**calloc_tiles(t_vec2i size)
{
	t_tile	**res;
	int		i;

	i = 0;
	res = malloc(size.y * sizeof(t_tile *));
	if (res == NULL)
		return (NULL);
	while (i < size.y)
	{
		res[i] = ft_calloc(size.x, sizeof(t_tile *));
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

t_tile	to_tile(char c)
{
	if (c == '1')
		return (wal);
	if (c == '0')
		return (ins);
	if (c == 'N')
		return (pno);
	if (c == 'S')
		return (pso);
	if (c == 'E')
		return (pea);
	if (c == 'W')
		return (pwe);
	return (out);
}
