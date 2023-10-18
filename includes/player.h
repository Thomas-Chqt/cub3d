/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:08:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 17:14:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

# define HIT_BOX_SIZE 0.2

struct s_play
{
	t_vec2f	pos;
	t_vec2f	dir;
	t_vec2f	plane;
	t_vec2f	hitb;
};

int		setup_player(t_play **dest, t_cubf *cubf);
void	pmove_fb(t_play *player, float dist, t_cubf *cubf);
void	pmove_lr(t_play *player, float dist, t_cubf *cubf);
void	protate(t_play *player, float rad);
void	clean_player(t_play *player);

t_vec2f	char_to_dir_vec(char c);
t_vec2f	char_to_plane_vec(char c);
t_bool	is_in_wall(t_play *play, t_vec2f pos, t_cubf *cubf);

#endif // PLAYER_H