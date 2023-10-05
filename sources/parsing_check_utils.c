/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:51:40 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/05 20:22:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "error.h"

t_bool	**calloc_visited(t_wh size)
{
	t_bool	**res;
	int		i;

	i = 0;
	res = malloc(size.h * sizeof(t_bool *));
	if (res == NULL)
		return (NULL);
	while (i < size.h)
	{
		res[i] = ft_calloc(size.w, sizeof(t_bool *));
		if (res[i] == NULL)
			break ;
		i++;
	}
	if (i == size.h)
		return (res);
	while (i >= 0)
		free(res[i--]);
	free(res);
	return (NULL);
}

void	free_visited(t_bool	**visited, t_wh size)
{
	int	i;

	i = 0;
	while (visited != NULL && i < size.h)
		free(visited[i++]);
	free(visited);
}
