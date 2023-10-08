/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:24:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/08 14:30:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "error.h"

static int	analize_and_add(char *line, t_list **line_lst, t_vec2i *size);
static int	convert_to_tiles(t_list **line_lst, t_cubf *cubf);

int	parse_cubf_map(int fd, t_cubf *cubf)
{
	char	*line;
	t_list	*line_lst;

	line_lst = NULL;
	skip_empty_lines(fd, &line);
	while (line != NULL)
	{
		if (analize_and_add(line, &line_lst, &cubf->size) != 0)
			return (free(line), ft_lstclear(&line_lst, &free_wrap), -1);
		g_file_err()->line++;
		line = get_next_line(fd);
	}
	if (cubf->size.y == 0)
		return (set_error(UNEP_EOF_ERROR), -1);
	if (convert_to_tiles(&line_lst, cubf) != 0)
		return (ft_lstclear(&line_lst, &free_wrap), -1);
	return (0);
}

static int	analize_and_add(char *line, t_list **line_lst, t_vec2i *size)
{
	size_t	tmp_len;
	t_list	*tmp;

	if (normalize_map_line(&line) != 0)
		return (-1);
	if (line[0] == '\0')
		return (set_error(PARSING_ERROR), -1);
	if (size->y == INT_MAX)
		return (set_error(BIG_MAP_ERROR), -1);
	size->y++;
	tmp_len = ft_strlen(line);
	if ((size_t)size->x < tmp_len)
		size->x = tmp_len;
	tmp = ft_lstnew(line);
	if (tmp == NULL)
		return (set_error(MALLOC_ERROR), -1);
	ft_lstadd_front(line_lst, tmp);
	return (0);
}

static int	convert_to_tiles(t_list **line_lst, t_cubf *cubf)
{
	int		x;
	int		y;
	t_list	*tmp;

	cubf->tiles = calloc_tiles(cubf->size);
	if (cubf->tiles == NULL)
		return (set_error(MALLOC_ERROR), -1);
	y = cubf->size.y;
	while (y > 0)
	{
		tmp = lst_rmvfrst(line_lst);
		x = 0;
		while (((char *)tmp->data)[x] != '\0')
		{
			cubf->tiles[y - 1][x] = to_tile(((char *)tmp->data)[x]);
			x++;
		}
		y--;
		ft_lstclear(&tmp, &free_wrap);
	}
	return (0);
}
