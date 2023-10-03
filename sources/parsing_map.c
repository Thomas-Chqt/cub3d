/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:46:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/03 17:36:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int		make_linelst(int fd, t_list **lines_lst, t_cubfile *cub);
static int		goto_map_start(int fd, char **line);
static int		make_tiles(t_list **lines_lst, t_cubfile *cub);

int	parse_map(int fd, t_cubfile *cub)
{
	t_list	*lines_lst;

	lines_lst = NULL;
	if (make_linelst(fd, &lines_lst, cub) != 0)
		return (1);
	if (make_tiles(&lines_lst, cub) != 0)
		return (1);
	return (0);
}

static int	make_linelst(int fd, t_list	**lines_lst, t_cubfile *cub)
{
	char	*line;
	t_list	*tmp;

	if (goto_map_start(fd, &line) != 0)
		return (1);
	while (cub->height < INT_MAX && line != NULL
		&& is_empty_str(line) == false)
	{
		normalize_line(line);
		if (is_valid_map_line(line) == false)
			return (free(line), ft_lstclear(lines_lst, &free_wrap),
				cub_perror_file("wrong character"), WRONG_CHARACTER);
		tmp = ft_lstnew(line);
		if (tmp == NULL)
			return (free(line), ft_lstclear(lines_lst, &free_wrap),
				cub_perror("malloc error"), MALLOC_ERROR);
		cub->height++;
		if (cub->width < ft_strlen(line))
			cub->width = ft_strlen(line);
		ft_lstadd_back(lines_lst, tmp);
		line = get_next_line(fd);
		cub_file_err()->line++;
	}
	return (0);
}

static int	goto_map_start(int fd, char **line)
{
	*line = get_next_line(fd);
	while (*line != NULL && is_empty_str(*line) == true)
	{
		free(*line);
		*line = get_next_line(fd);
		cub_file_err()->line++;
	}
	if (*line == NULL)
		return (cub_perror_file("unexpected EOF"), 1);
	return (0);
}

static int	make_tiles(t_list **lines_lst, t_cubfile *cub)
{
	t_list	*tmp;
	t_pos	pos;

	cub->tiles = ft_calloc(cub->height * cub->width, sizeof(t_tile *));
	if (cub->tiles == NULL)
		return (cub_perror("malloc error"), MALLOC_ERROR);
	pos.y = 0;
	while (pos.y < cub->height)
	{
		tmp = lst_rmvfrst(lines_lst);
		pos.x = 0;
		while (pos.x < cub->width && ((char *)tmp->data)[pos.x] != '\0')
		{
			*get_tile(*cub, pos) = to_tile(((char *)tmp->data)[pos.x]);
			pos.x++;
		}
		pos.y++;
		ft_lstclear(&tmp, &free_wrap);
	}
	return (0);
}
