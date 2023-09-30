/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:55:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/30 17:23:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	load_map(char *file)
{
	t_map	map;
	
	map.tiles = malloc(sizeof(t_tile) * 3);
	
	for (size_t i = 0; i < 3; i++)
		map.tiles[i] = malloc(sizeof(t_tile) * 3);
		
	map.tiles[0][0] = wall; map.tiles[0][1] = wall; map.tiles[0][2] = wall;
	map.tiles[1][0] = wall; map.tiles[1][1] = none; map.tiles[1][2] = wall;
	map.tiles[2][0] = wall; map.tiles[2][1] = wall; map.tiles[2][2] = wall;
	
	map.size = (t_wh){3 ,3};
	
	return (map);
}
