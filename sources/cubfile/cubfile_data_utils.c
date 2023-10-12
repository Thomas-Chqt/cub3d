/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:12:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/12 17:29:31 by tchoquet         ###   ########.fr       */
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
		|| is_uint8(splited_line[1]) == false || is_uint8(splited_line[2]) == false)
		return (set_error((0b1100 << 28) | PARSING),
			free_splited_str(splited_line), NULL);
	return (splited_line);
}
