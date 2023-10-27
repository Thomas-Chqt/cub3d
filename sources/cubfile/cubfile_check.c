/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:21:46 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/27 12:21:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubfile_internal.h"

static int	bfs(t_cubf *cubf, t_vec2i pos, t_bool **visited,
				t_uint32 *stack_count);

int	check_map(t_cubf *cubf)
{
	t_bool		**visited;
	int			result;
	t_uint32	stack_count;

	visited = calloc_visited(cubf->map.size);
	if (visited == NULL)
		return (set_error(MALLOC_ERROR), -1);
	result = bfs(cubf, cubf->map.player->pos, visited, &stack_count);
	free_visited(visited, cubf->map.size);
	if (result != 0)
		return (-1);
	return (0);
}

static int	bfs(t_cubf *cubf, t_vec2i pos, t_bool **visited,
				t_uint32 *stack_count)
{
	if ((*stack_count)++ == 170000)
		return (set_error(BIG_MAP_ERROR), -1);
	if (visited[pos.y][pos.x] == true || get_mtile(cubf, pos) == wall)
		return (0);
	visited[pos.y][pos.x] = true;
	*cub_error_line() = pos.y + 1;
	*cub_error_column() = pos.x + 1;
	if (get_mtile(cubf, (t_vec2i){pos.x + 1, pos.y}) == out_map)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (get_mtile(cubf, (t_vec2i){pos.x, pos.y + 1}) == out_map)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (get_mtile(cubf, (t_vec2i){pos.x - 1, pos.y}) == out_map)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (get_mtile(cubf, (t_vec2i){pos.x, pos.y - 1}) == out_map)
		return (set_error(NOT_CLOSE_ERROR), -1);
	if (bfs(cubf, (t_vec2i){pos.x + 1, pos.y}, visited, stack_count) != 0
		|| bfs(cubf, (t_vec2i){pos.x, pos.y + 1}, visited, stack_count) != 0
		|| bfs(cubf, (t_vec2i){pos.x - 1, pos.y}, visited, stack_count) != 0
		|| bfs(cubf, (t_vec2i){pos.x, pos.y - 1}, visited, stack_count) != 0)
		return (--(*stack_count), -1);
	return (--(*stack_count), 0);
}
