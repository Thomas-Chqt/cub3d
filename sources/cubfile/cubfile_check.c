/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:21:46 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 16:02:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

static int	bfs(t_mtile **map, t_vec2i size, t_vec2i pos, t_bool **visited);

int	check_map(void)
{
	t_bool	**visited;
	int		result;

	visited = calloc_visited(cub3d()->m_size);
	if (visited == NULL)
		return (set_error(MALLOC_ERROR), -1);
	result = bfs(cub3d()->map, cub3d()->m_size,
			vf2tovi2(cub3d()->p_pos), visited);
	free_visited(visited, cub3d()->m_size);
	if (result != 0)
		return (-1);
	return (0);
}

static int	bfs(t_mtile **map, t_vec2i size, t_vec2i pos, t_bool **visited)
{
	if (visited[pos.y][pos.x] == true || map[pos.y][pos.x] >= wall)
		return (0);
	visited[pos.y][pos.x] = true;
	cub_error()->line = pos.y + 1;
	cub_error()->column = pos.x + 1;
	if (pos.y - 1 < 0 || pos.x < 0 || pos.y - 1 >= size.y || pos.x >= size.x
		|| map[pos.y - 1][pos.x] == 0)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (pos.y + 1 < 0 || pos.x < 0 || pos.y + 1 >= size.y || pos.x >= size.x
		|| map[pos.y + 1][pos.x] == 0)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (pos.y < 0 || pos.x - 1 < 0 || pos.y >= size.y || pos.x - 1 >= size.x
		|| map[pos.y][pos.x - 1] == 0)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (pos.y < 0 || pos.x + 1 < 0 || pos.y >= size.y || pos.x + 1 >= size.x
		|| map[pos.y][pos.x + 1] == 0)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (bfs(map, size, (t_vec2i){pos.x + 1, pos.y}, visited) != 0
		|| bfs(map, size, (t_vec2i){pos.x, pos.y + 1}, visited) != 0
		|| bfs(map, size, (t_vec2i){pos.x - 1, pos.y}, visited) != 0
		|| bfs(map, size, (t_vec2i){pos.x, pos.y - 1}, visited) != 0)
		return (-1);
	return (0);
}
