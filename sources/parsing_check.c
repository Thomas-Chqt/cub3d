/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:50:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/08 14:30:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "error.h"

static int	find_p_start(t_cubf *cubf);
static int	dfs(t_cubf *cubf, t_vec2i pos, t_bool **visited);

int	check_cubf_map(t_cubf *cubf)
{
	t_bool	**visited;
	int		result;

	if (find_p_start(cubf) != 0)
		return (-1);
	visited = calloc_visited(cubf->size);
	if (visited == NULL)
		return (set_error(MALLOC_ERROR), -1);
	result = dfs(cubf, cubf->p_start, visited);
	free_visited(visited, cubf->size);
	if (result != 0)
		return (-1);
	return (0);
}

static int	find_p_start(t_cubf *cubf)
{
	int	x;
	int	y;

	g_map_err()->collum = 0;
	g_map_err()->row = 0;
	y = -1;
	while (++y < cubf->size.y)
	{
		g_map_err()->row++;
		x = -1;
		g_map_err()->collum = 0;
		while (++x < cubf->size.x)
		{
			g_map_err()->collum++;
			if (cubf->tiles[y][x] <= ins)
				continue ;
			if (cubf->p_start_rot >= pno)
				return (set_error(DOUBLE_P_ERROR), -1);
			cubf->p_start = (t_vec2i){x, y};
			cubf->p_start_rot = cubf->tiles[y][x];
		}
	}
	if (cubf->p_start_rot < pno)
		return (set_error(NO_PLAYER_ERROR), -1);
	return (0);
}

static int	dfs(t_cubf *cubf, t_vec2i pos, t_bool **visited)
{
	g_map_err()->collum = pos.x + 1;
	g_map_err()->row = pos.y + 1;
	if (pos.y < 0 || pos.x < 0)
		return (set_error(NOT_CLOSED_ERROR), -1);
	if (pos.y >= cubf->size.y || pos.x >= cubf->size.x)
		return (set_error(NOT_CLOSED_ERROR), -1);
	if (visited[pos.y][pos.x] == true)
		return (0);
	if (cubf->tiles[pos.y][pos.x] == wal)
		return (0);
	visited[pos.y][pos.x] = true;
	if (dfs(cubf, (t_vec2i){pos.x + 1, pos.y}, visited) != 0)
		return (-1);
	if (dfs(cubf, (t_vec2i){pos.x, pos.y + 1}, visited) != 0)
		return (-1);
	if (dfs(cubf, (t_vec2i){pos.x - 1, pos.y}, visited) != 0)
		return (-1);
	if (dfs(cubf, (t_vec2i){pos.x, pos.y - 1}, visited) != 0)
		return (-1);
	return (0);
}
