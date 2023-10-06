/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:18:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 12:20:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "error.h"

t_bool	is_data_all_parsed(t_cubf *cubf)
{
	if (cubf->no_tex == NULL)
		return (false);
	if (cubf->so_tex == NULL)
		return (false);
	if (cubf->we_tex == NULL)
		return (false);
	if (cubf->ea_tex == NULL)
		return (false);
	if (cubf->f_col == TRANSP)
		return (false);
	if (cubf->c_col == TRANSP)
		return (false);
	return (true);
}

void	goto_line_start(char **line_ptr)
{
	t_uint64	i;

	i = 0;
	while (is_whitespace((*line_ptr)[i]))
		i++;
	(*line_ptr) += i;
}

void	normalize_line(char **line_ptr)
{
	t_uint64	i;

	i = 0;
	while ((*line_ptr)[i] != '\0' && (*line_ptr)[i] != '\n')
		i++;
	(*line_ptr)[i] = '\0';
}

t_bool	is_color_comp_sep(char c)
{
	return (is_whitespace(c) == true || c == ',');
}
