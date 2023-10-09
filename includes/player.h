/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:16:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/09 22:42:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

t_vec2f	tile_to_vect_dir(t_tile tile);
t_vec2f	tile_to_vect_plane(t_tile tile);
t_bool	is_in_wall(t_vec2f p_pos);

#endif // PLAYER_H