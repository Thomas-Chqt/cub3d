/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:21:46 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 15:20:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

static int	bfs(t_cubf *cubf, t_vec2i pos, t_bool **visited);

int	check_map(t_cubf *cubf)
{
	t_bool	**visited;
	int		result;

	visited = calloc_visited(cubf->m_size);
	if (visited == NULL)
		return (set_error(MALLOC_ERROR), -1);
	result = bfs(cubf, cubf->p_srt_pos, visited);
	free_visited(visited, cubf->m_size);
	if (result != 0)
		return (-1);
	return (0);
}

static int	bfs(t_cubf *cubf, t_vec2i pos, t_bool **visited)
{
	if (visited[pos.y][pos.x] == true || cubf->map[pos.y][pos.x] >= wall)
		return (0);
	visited[pos.y][pos.x] = true;
	cub_error()->line = pos.y + 1;
	cub_error()->column = pos.x + 1;
	if (pos.y - 1 < 0 || pos.x < 0 || pos.y - 1 >= cubf->m_size.y || pos.x
		>= cubf->m_size.x || cubf->map[pos.y - 1][pos.x] == 0)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (pos.y + 1 < 0 || pos.x < 0 || pos.y + 1 >= cubf->m_size.y || pos.x
		>= cubf->m_size.x || cubf->map[pos.y + 1][pos.x] == 0)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (pos.y < 0 || pos.x - 1 < 0 || pos.y >= cubf->m_size.y || pos.x - 1
		>= cubf->m_size.x || cubf->map[pos.y][pos.x - 1] == 0)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (pos.y < 0 || pos.x + 1 < 0 || pos.y >= cubf->m_size.y || pos.x + 1
		>= cubf->m_size.x || cubf->map[pos.y][pos.x + 1] == 0)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (bfs(cubf, (t_vec2i){pos.x + 1, pos.y}, visited) != 0
		|| bfs(cubf, (t_vec2i){pos.x, pos.y + 1}, visited) != 0
		|| bfs(cubf, (t_vec2i){pos.x - 1, pos.y}, visited) != 0
		|| bfs(cubf, (t_vec2i){pos.x, pos.y - 1}, visited) != 0)
		return (-1);
	return (0);
}
