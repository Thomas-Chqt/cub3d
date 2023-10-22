/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:11:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 12:10:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubfile_internal.h"

static int	load_line(t_cubf_map *map, char *line, t_list **line_lst);
static int	process_char(t_cubf_map *map, char src, char *dest, t_vec2i pos);
static int	convert_to_tiles(t_cubf_map *map, t_list **line_lst);

int	load_map(t_cubf_map *map, int fd)
{
	char	*line;
	t_list	*line_lst;

	line_lst = NULL;
	line = gnl_no_empty(fd);
	if (line == NULL)
		return (set_error(UNEXP_EOF_ERROR), -1);
	while (line != NULL)
	{
		if (load_line(map, line, &line_lst) != 0)
			return (free_all(line, &line_lst, map), -1);
		line = get_next_line(fd);
		if (line != NULL && is_empty_str(line) && is_file_over(fd) == false)
			return (free_all(line, &line_lst, map),
				set_error(PARSING_ERROR), -1);
	}
	if (map->player == NULL)
		return (free_all(line, &line_lst, map), set_error(NO_P_ERROR), -1);
	if (convert_to_tiles(map, &line_lst) != 0)
		return (free_all(line, &line_lst, map), -1);
	return (0);
}

void	clean_map(t_cubf_map *map)
{
	int	i;

	i = 0;
	while (map->tiles != NULL && i < map->size.y)
		free(map->tiles[i++]);
	free(map->tiles);
	map->tiles = NULL;
	ft_lstclear(&map->entity_lst, &free_wrap);
}

static int	load_line(t_cubf_map *map, char *line, t_list **line_lst)
{
	int		x;
	t_list	*new_node;

	if (map->size.y++ == INT_MAX)
		return (set_error(BIG_MAP_ERROR), -1);
	x = 0;
	while (line[x] != '\0' && line[x] != '\n')
	{
		if (x == INT_MAX)
			return (set_error(LONG_LINE_ERROR), -1);
		*cub_error_column() = x + 1;
		if (process_char(map, line[x], line + x,
				(t_vec2i){x, map->size.y - 1}) != 0)
			return (-1);
		x++;
	}
	line[x] = '\0';
	map->size.x = imax(map->size.x, x);
	new_node = ft_lstnew(line);
	if (new_node == NULL)
		return (set_error(MALLOC_ERROR), -1);
	ft_lstadd_front(line_lst, new_node);
	(*cub_error_line())++;
	return (0);
}

static int	process_char(t_cubf_map *map, char src, char *dest, t_vec2i pos)
{
	if (ft_strchr(" 10", src) != NULL)
		return (*dest = src, 0);
	if (ft_strchr("NSEW", src) != NULL)
	{
		if (map->player != NULL)
			return (set_error(DOUBLE_P_ERROR), -1);
		map->player = add_ent(&map->entity_lst, pos, src);
		if (map->player == NULL)
			return (set_error(MALLOC_ERROR), -1);
		return (*dest = '0', 0);
	}
	if (ft_strchr("X", src))
	{
		if (add_ent(&map->entity_lst, pos, src) == NULL)
			return (set_error(MALLOC_ERROR), -1);
		return (*dest = '0', 0);
	}
	return (set_error(BAD_CHAR_ERROR), -1);
}

static int	convert_to_tiles(t_cubf_map *map, t_list **line_lst)
{
	t_vec2i	curr;
	t_list	*node;

	map->tiles = calloc_tiles(map->size);
	if (map->tiles == NULL)
		return (set_error(MALLOC_ERROR), -1);
	curr.y = map->size.y;
	while (curr.y > 0)
	{
		curr.x = 0;
		node = lst_rmvfrst(line_lst);
		while (((char *)node->data)[curr.x] != '\0')
		{
			if (((char *)node->data)[curr.x] == '0')
				map->tiles[curr.y - 1][curr.x] = empty;
			if (((char *)node->data)[curr.x] == '1')
				map->tiles[curr.y - 1][curr.x] = wall;
			curr.x++;
		}
		ft_lstclear(&node, &free_wrap);
		curr.y--;
	}
	return (0);
}
