/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:38:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/03 17:28:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	normalize_line(char *line)
{
	int	i;

	i = 0;
	while (i < INT_MAX && line[i] != '\n' && line[i] != '\0')
		i++;
	line[i] = '\0';
}

t_bool	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr(" 01NSEW", line[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}

t_tile	to_tile(char c)
{
	if (c == ' ')
		return (out);
	if (c == '0')
		return (empty);
	if (c == 'N')
		return (p_no);
	if (c == 'S')
		return (p_so);
	if (c == 'E')
		return (p_ea);
	if (c == 'W')
		return (p_we);
	if (c == '1')
		return (wall);
	return (out);
}
