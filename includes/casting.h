/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:26:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 20:26:14 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

# include "cub3d.h"

typedef struct s_dda
{
	t_vec2f	start;
	t_vec2f	dir;

	t_vec2i	tile_step;
	t_vec2i	curr_tile;

	t_vec2f	length_step;
	t_vec2f	curr_length;

	t_side	v_side;
	t_side	h_side;

}	t_dda;

t_dda	init_dda(t_vec2f start, t_vec2f dir);

#endif // CASTING_H