/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:29:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 15:30:10 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

t_bool	**calloc_visited(t_vec2i size)
{
	t_bool	**res;
	int		i;

	i = 0;
	res = malloc(size.y * sizeof(t_bool *));
	if (res == NULL)
		return (NULL);
	while (i < size.y)
	{
		res[i] = ft_calloc(size.x, sizeof(t_bool *));
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

void	free_visited(t_bool	**visited, t_vec2i size)
{
	int	i;

	i = 0;
	while (visited != NULL && i < size.y)
		free(visited[i++]);
	free(visited);
}
