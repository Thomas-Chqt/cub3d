/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:46:48 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/02 22:28:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	goto_map_start(int fd, char **line);
static int	make_tiles(t_tile ***tiles, t_list *lines_lst);

int	parse_map(int fd, t_cubfile *cub)
{
	char		*line;
	t_list		*tmp;
	t_list		*lines_lst;
	t_uint64	i;

	if (goto_map_start(fd, &line) != 0);
		return (1);	
	while (line != NULL && is_empty_str(line) == false)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (ft_strchr(" 01NSEW", line[i++]) == NULL)
				return (free(line), ft_lstclear(&lines_lst, &free_wrap),
					cub_perror("malloc error"), MALLOC_ERROR);
		}

		tmp = ft_lstnew(line);
		if (tmp == NULL)
			return (free(line), ft_lstclear(&lines_lst, &free_wrap),
				cub_perror("malloc error"), MALLOC_ERROR);
		ft_lstadd_back(&lines_lst, tmp);
		cub_file_err()->line++;
	}
}

static int	goto_map_start(int fd, char **line)
{
	*line = get_next_line(fd);
	while (line != NULL && is_empty_str(line) == true)
	{
		line = get_next_line(fd);
		cub_file_err()->line++;
	}
	if (line == NULL)
		return (cub_perror_file("Unexpected EOF"), 1);
	return (0);
}

static int	make_tiles(t_tile ***tiles, t_list *lines_lst)
{
	t_list	*watched;
	
	*tiles = malloc(sizeof(t_tile *) * ft_lstsize(lines_lst));
	watched = lines_lst;
	while (watched != NULL)
	{
		f(watched->data);
		watched = watched->next;
	}
}
