/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:11:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 13:24:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"
#include "sprite.h"

int	load_line(t_cubf *cubf, char *line, t_list **line_lst);
int	process_char(t_cubf *cubf, char src, char *dest, t_vec2i pos);
int	convert_to_tiles(t_cubf *cubf, t_list **line_lst);

int	load_map(t_cubf *cubf, int fd)
{
	char	*line;
	t_list	*line_lst;

	line_lst = NULL;
	line = gnl_no_empty(fd);
	if (line == NULL)
		return (set_error(UNEXP_EOF_ERROR), -1);
	while (line != NULL)
	{
		if (load_line(cubf, line, &line_lst) != 0)
			return (free(line), ft_lstclear(&line_lst, &free_wrap),
				ft_lstclear(&cubf->sp_lst, (t_vf)free_sprite), -1);
		line = get_next_line(fd);
		if (line != NULL && is_empty_str(line) && is_file_over(fd) == false)
			return (free(line), ft_lstclear(&line_lst, &free_wrap),
				ft_lstclear(&cubf->sp_lst, (t_vf)free_sprite),
				set_error(PARSING_ERROR), -1);
	}
	if (cubf->p_srt_dir == 0)
		return (ft_lstclear(&line_lst, &free_wrap), ft_lstclear(&cubf->sp_lst,
				(t_vf)free_sprite), set_error(NO_P_ERROR), -1);
	if (convert_to_tiles(cubf, &line_lst) != 0)
		return (ft_lstclear(&line_lst, &free_wrap), ft_lstclear(&cubf->sp_lst,
				(t_vf)free_sprite), -1);
	return (0);
}

int	load_line(t_cubf *cubf, char *line, t_list **line_lst)
{
	int		x;
	t_list	*new_node;

	if (cubf->m_size.y++ == INT_MAX)
		return (set_error(BIG_MAP_ERROR), -1);
	x = 0;
	while (line[x] != '\0' && line[x] != '\n')
	{
		if (x == INT_MAX)
			return (set_error(LONG_LINE_ERROR), -1);
		cub_error()->column = x + 1;
		if (process_char(cubf, line[x], line + x,
				(t_vec2i){x, cubf->m_size.y - 1}) != 0)
			return (-1);
		x++;
	}
	line[x] = '\0';
	if (cubf->m_size.x < x)
		cubf->m_size.x = x;
	new_node = ft_lstnew(line);
	if (new_node == NULL)
		return (set_error(MALLOC_ERROR), -1);
	ft_lstadd_front(line_lst, new_node);
	cub_error()->line++;
	return (0);
}

int	process_char(t_cubf *cubf, char src, char *dest, t_vec2i pos)
{
	if (ft_strchr(" 10", src) != NULL)
		return (*dest = src, 0);
	if (ft_strchr("NSEW", src) != NULL)
	{
		if (cubf->p_srt_dir != 0)
			return (set_error(DOUBLE_P_ERROR), -1);
		cubf->p_srt_pos = pos;
		cubf->p_srt_dir = src;
		return (*dest = '0', 0);
	}
	if (src == 'X')
	{
		if (add_new_ss_sprite(&cubf->sp_lst,
				(t_vec2f){(float)pos.x + 0.5f, (float)pos.y + 0.5f}) != 0)
			return (-1);
		return (*dest = '0', 0);
	}
	set_error(BAD_CHAR_ERROR);
	return (-1);
}

int	convert_to_tiles(t_cubf *cubf, t_list **line_lst)
{
	t_vec2i	curr;
	t_list	*node;

	cubf->map = calloc_tiles(cubf->m_size);
	if (cubf->map == NULL)
		return (set_error(MALLOC_ERROR), -1);
	curr.y = cubf->m_size.y;
	while (curr.y > 0)
	{
		curr.x = 0;
		node = lst_rmvfrst(line_lst);
		while (((char *)node->data)[curr.x] != '\0')
		{
			if (((char *)node->data)[curr.x] == '0')
				cubf->map[curr.y - 1][curr.x] = empty;
			if (((char *)node->data)[curr.x] == '1')
				cubf->map[curr.y - 1][curr.x] = wall;
			curr.x++;
		}
		ft_lstclear(&node, &free_wrap);
		curr.y--;
	}
	return (0);
}
