/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:00:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 14:39:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

t_bool	is_all_data_loaded(t_cubf *cubf)
{
	if (cubf->no_tex == NULL)
		return (false);
	if (cubf->so_tex == NULL)
		return (false);
	if (cubf->we_tex == NULL)
		return (false);
	if (cubf->ea_tex == NULL)
		return (false);
	if (cubf->c_color == TRANSP)
		return (false);
	if (cubf->f_color == TRANSP)
		return (false);
	return (true);
}

char	*normed(char *line)
{
	long	i;

	while (is_whitespace(*line))
		line++;
	i = ft_strlen(line) - 1;
	while (i >= 0 && is_whitespace(line[i]))
		line[i--] = '\0';
	return (line);
}

char	**parse_color_comp(char *line)
{
	char	**spl_line;

	if (str_charcount(line, ',') != 2)
		return (set_error(PARSING_ERROR), NULL);
	spl_line = ft_split(line, ',');
	if (spl_line == NULL)
		return (set_error(MALLOC_ERROR), NULL);
	if (arrstr_len(spl_line) != 3)
		return (set_error(PARSING_ERROR), free_splited_str(spl_line), NULL);
	if (is_uint8(normed(spl_line[0])) == false)
		return (set_error(PARSING_ERROR), free_splited_str(spl_line), NULL);
	if (is_uint8(normed(spl_line[1])) == false)
		return (set_error(PARSING_ERROR), free_splited_str(spl_line), NULL);
	if (is_uint8(normed(spl_line[2])) == false)
		return (set_error(PARSING_ERROR), free_splited_str(spl_line), NULL);
	return (spl_line);
}
