/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:12:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/12 21:48:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

t_bool	is_all_data_loaded(void)
{
	t_cub3d	*cub;

	cub = cub3d();
	if (cub->no_tex == NULL)
		return (false);
	if (cub->so_tex == NULL)
		return (false);
	if (cub->we_tex == NULL)
		return (false);
	if (cub->ea_tex == NULL)
		return (false);
	if (cub->c_color == TRANSP)
		return (false);
	if (cub->f_color == TRANSP)
		return (false);
	return (true);
}

char	*gnl_no_empty(int fd)
{
	char	*line;

	cub_error()->y++;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_empty_str(line) == false)
			return (line);
		free(line);
		cub_error()->y++;
		line = get_next_line(fd);
	}
	return (line);
}

char	*normalized_line(char *line)
{
	long	i;

	while (is_whitespace(*line))
		line++;
	i = ft_strlen(line) - 1;
	while (i >= 0 && is_whitespace(line[i]))
		line[i--] = '\0';
	return (line);
}

char	**split_color_comp(char *str)
{
	char		**splited_line;
	t_uint64	i;
	int			count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			count++;
		if (count > 2)
			return (set_error((0b1100 << 28) | PARSING), NULL);
		i++;
	}
	if (count < 2)
		return (set_error((0b1100 << 28) | PARSING), NULL);
	splited_line = ft_split(str, ',');
	if (splited_line == NULL)
		return (set_error((0b0000 << 28) | MALLOC), NULL);
	if (arrstr_len(splited_line) != 3 || is_uint8(splited_line[0]) == false
		|| is_uint8(splited_line[1]) == false
		|| is_uint8(splited_line[2]) == false)
		return (set_error((0b1100 << 28) | PARSING),
			free_splited_str(splited_line), NULL);
	return (splited_line);
}

int	add_line(char *line, t_list **list)
{
	int		i;
	t_list	*new_node;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (i == INT_MAX)
			return (set_error((0b1100 << 28) | LONG_LINE), -1);
		i++;
	}
	line[i] = '\0';
	if (cub3d()->m_size.x < i)
		cub3d()->m_size.x = i;
	if (cub3d()->m_size.y == INT_MAX)
		return (set_error((0b1100 << 28) | BIG_MAP), -1);
	cub3d()->m_size.y++;
	new_node = ft_lstnew(line);
	if (new_node == NULL)
		return (set_error((0b0000 << 28) | MALLOC), -1);
	ft_lstadd_front(list, new_node);
	return (0);
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

void	set_player_vec(t_vec2i pos, char dir)
{
	cub3d()->p_pos.x = (float)pos.x + 0.5f;
	cub3d()->p_pos.y = (float)pos.y + 0.5f;
	if (dir == 'N')
	{
		cub3d()->p_dir = (t_vec2f){.x = 0.0f, .y = -1.0f};
		cub3d()->p_plane = (t_vec2f){
			.x = tanf(torad((float)FOV / 2.0f)), .y = 0.0f};
		return ;
	}
	else if (dir == 'S')
	{
		cub3d()->p_dir = (t_vec2f){.x = 0.0f, .y = 1.0f};
		cub3d()->p_plane = (t_vec2f){
			.x = -tanf(torad((float)FOV / 2.0f)), .y = 0.0f};
		return ;
	}
	else if (dir == 'E')
	{
		cub3d()->p_dir = (t_vec2f){.x = 1.0f, .y = 0.0f};
		cub3d()->p_plane = (t_vec2f){
			.x = 0.0f, .y = tanf(torad((float)FOV / 2))};
		return ;
	}
	cub3d()->p_dir = (t_vec2f){.x = -1.0f, .y = 0.0f};
	cub3d()->p_plane = (t_vec2f){.x = 0.0f, .y = -tanf(torad((float)FOV / 2))};
}
