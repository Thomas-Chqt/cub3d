/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:06:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/12 21:42:26 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

static t_list	*make_line_list(int fd);
static int		load_line_lst(t_list **line_lst);
static int		load_line(char *line, int y);

int	load_map(int fd)
{
	t_list	*line_lst;

	line_lst = make_line_list(fd);
	if (line_lst == NULL)
		return (-1);
	if (load_line_lst(&line_lst) != 0)
		return (ft_lstclear(&line_lst, &free_wrap), -1);
	return (0);
}

static t_list	*make_line_list(int fd)
{
	char	*line;
	t_list	*line_lst;

	line_lst = NULL;
	line = gnl_no_empty(fd);
	if (line == NULL)
		return (set_error((0b1100 << 28) | UNEXP_EOF), NULL);
	while (line != NULL && is_empty_str(line) == false)
	{
		if (add_line(line, &line_lst) != 0)
			return (free(line), ft_lstclear(&line_lst, &free_wrap), NULL);
		cub_error()->y++;
		line = get_next_line(fd);
	}
	while (line != NULL && is_empty_str(line) == true)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		return (free(line), ft_lstclear(&line_lst, &free_wrap),
			set_error((0b1100 << 28) | PARSING), NULL);
	return (line_lst);
}

static int	load_line_lst(t_list **line_lst)
{
	int		y;
	t_list	*tmp;
	int		ret;

	cub3d()->map = calloc_tiles(cub3d()->m_size);
	if (cub3d()->map == NULL)
		return (set_error((0b0000 << 28) | MALLOC), -1);
	y = cub3d()->m_size.y;
	while (y > 0)
	{
		cub_error()->y = y;
		tmp = lst_rmvfrst(line_lst);
		ret = load_line((char *)tmp->data, y - 1);
		ft_lstclear(&tmp, &free_wrap);
		if (ret != 0)
			return (-1);
		y--;
	}
	if (cub3d()->p_dir.x == 0.0f && cub3d()->p_dir.y == 0.0f)
		return (set_error((0b1000 << 28) | NO_PLAYER), -1);
	return (0);
}

static int	load_line(char *line, int y)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		cub_error()->x = x + 1;
		if (line[x] == '1')
			cub3d()->map[y][x] = wall;
		else if (line[x] == '0')
			cub3d()->map[y][x] = empty;
		else if (ft_strchr("NSEW", line[x]) != NULL)
		{
			if (cub3d()->p_dir.x != 0.0f || cub3d()->p_dir.y != 0.0f)
				return (set_error((0b1110 << 28) | DOUBLE_P), -1);
			set_player_vec((t_vec2i){x, y}, line[x]);
		}
		else if (line[x] == ' ')
			;
		else
			return (set_error((0b1110 << 28) | WRONG_CHAR), -1);
		x++;
	}
	return (0);
}
