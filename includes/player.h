/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:08:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 14:36:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"
# include "timer.h"
# include "sprite.h"

# define HIT_BOX_SIZE 0.2

struct s_play
{
	t_vec2f	pos;
	t_vec2f	dir;
	t_vec2f	plane;
	t_vec2f	hitb;

	t_timer	reload_timer;
};

int		setup_player(t_play **dest, t_cubf *cubf);
void	pmove_fb(t_play *player, float dist, t_cubf *cubf);
void	pmove_lr(t_play *player, float dist, t_cubf *cubf);
void	protate(t_play *player, float rad);
void	pshoot(t_play *player, t_sprite *target, t_hud *hud);

t_vec2f	char_to_dir_vec(char c);
t_vec2f	char_to_plane_vec(char c);
t_bool	is_in_wall(t_play *play, t_vec2f pos, t_cubf *cubf);

#endif // PLAYER_H