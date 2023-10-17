/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:11:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 19:14:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"
#include "sprite.h"

int	load_line(char *line, t_list **line_lst, int y);
int	process_char(char src, char *dest, t_vec2i pos);
int	convert_to_tiles(t_list **line_lst);

int	load_map(int fd)
{
	char	*line;
	t_list	*line_lst;
	int		y;

	line_lst = NULL;
	line = gnl_no_empty(fd);
	if (line == NULL)
		return (set_error(UNEXP_EOF_ERROR), -1);
	y = 0;
	while (line != NULL)
	{
		if (load_line(line, &line_lst, y++) != 0)
			return (free(line), ft_lstclear(&line_lst, &free_wrap), -1);
		cub_error()->line++;
		line = get_next_line(fd);
		if (line != NULL && is_empty_str(line) && is_file_over(fd) == false)
			return (free(line), ft_lstclear(&line_lst, &free_wrap),
				set_error(PARSING_ERROR), -1);
	}
	if (cub3d()->p_dir.x == 0 && cub3d()->p_dir.y == 0)
		return (ft_lstclear(&line_lst, &free_wrap), set_error(NO_P_ERROR), -1);
	if (convert_to_tiles(&line_lst) != 0)
		return (ft_lstclear(&line_lst, &free_wrap), -1);
	return (0);
}

int	load_line(char *line, t_list **line_lst, int y)
{
	int		x;
	t_list	*new_node;

	if (cub3d()->m_size.y++ == INT_MAX)
		return (set_error(BIG_MAP_ERROR), -1);
	x = 0;
	while (line[x] != '\0' && line[x] != '\n')
	{
		if (x == INT_MAX)
			return (set_error(LONG_LINE_ERROR), -1);
		cub_error()->column = x + 1;
		if (process_char(line[x], line + x, (t_vec2i){x, y}) != 0)
			return (-1);
		x++;
	}
	line[x] = '\0';
	if (cub3d()->m_size.x < x)
		cub3d()->m_size.x = x;
	new_node = ft_lstnew(line);
	if (new_node == NULL)
		return (set_error(MALLOC_ERROR), -1);
	ft_lstadd_front(line_lst, new_node);
	return (0);
}

int	process_char(char src, char *dest, t_vec2i pos)
{
	if (ft_strchr(" 10", src) != NULL)
		return (*dest = src, 0);
	if (ft_strchr("NSEW", src) != NULL)
	{
		if (cub3d()->p_dir.x != 0 || cub3d()->p_dir.y != 0)
			return (set_error(DOUBLE_P_ERROR), -1);
		cub3d()->p_pos.x = (float)pos.x + 0.5f;
		cub3d()->p_pos.y = (float)pos.y + 0.5f;
		set_player_dir(src);
		set_player_plane(src);
		return (*dest = '0', 0);
	}
	if (src == 'X')
	{
		if (new_sprite((t_vec2f){(float)pos.x + 0.5f,
				(float)pos.y + 0.5f}, ss) != 0)
			return (-1);
		return (*dest = '0', 0);
	}
	set_error(BAD_CHAR_ERROR);
	return (-1);
}

int	convert_to_tiles(t_list **line_lst)
{
	t_vec2i	curr;
	t_list	*node;

	cub3d()->map = calloc_tiles(cub3d()->m_size);
	if (cub3d()->map == NULL)
		return (set_error(MALLOC_ERROR), -1);
	curr.y = cub3d()->m_size.y;
	while (curr.y > 0)
	{
		curr.x = 0;
		node = lst_rmvfrst(line_lst);
		while (((char *)node->data)[curr.x] != '\0')
		{
			if (((char *)node->data)[curr.x] == '0')
				cub3d()->map[curr.y - 1][curr.x] = empty;
			if (((char *)node->data)[curr.x] == '1')
				cub3d()->map[curr.y - 1][curr.x] = wall;
			curr.x++;
		}
		ft_lstclear(&node, &free_wrap);
		curr.y--;
	}
	return (0);
}
