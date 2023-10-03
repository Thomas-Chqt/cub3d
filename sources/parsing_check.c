/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:41:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/03 18:03:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	find_player(t_cubfile *cub);

int	check_map(t_cubfile *cub)
{
	// if (find_player(cub) != 0)
	// 	return (cub_perror())
	return (0);
}

static int	find_player(t_cubfile *cub)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < cub->height)
	{
		pos.x = 0;
		while (pos.x < cub->width)
		{
			if (*get_tile(*cub, pos) > empty)
			{
				cub->p_pos = pos;
				cub->p_dir = *get_tile(*cub, pos);
				return (0);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}
