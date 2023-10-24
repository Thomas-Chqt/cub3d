/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:22:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 14:00:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_INTERNAL_H
# define ENTITY_INTERNAL_H

# include "entity.h"
# include "cubfile.h"
# include "error.h"
# include "animation.h"
# include "dda.h"

# define ENT_HBOX 0.2

# define HUD_SIZE_X	600
# define HUD_SIZE_Y	600

struct s_ent
{
	t_vec2f	pos;
	t_vec2f	dir;
	t_vec2f	pla;

	int		hp;
	int		dmg;

	t_timer	cooldown;
	t_timer	reaction;

	t_ctx	*img;
	t_anim	curr_anim;
	t_anim	idle_anim;
	t_anim	die_anim;
	t_anim	shoot_anim;

	t_vec2i	s_pos;
	float	s_dep;
};

int		create_ent(t_ent **dest, t_cfent *cfent);
t_bool	is_ent_closer(t_ent *a, t_ent *b, t_ent *pl);
int		fill_ss_anim(t_ent *ent);
int		fill_hud_anim(t_ent *ent);
void	fill_setup_data(t_ent *ent, char id);

void	rot_to_player(t_ent *ent, t_ent *pl);
void	update_screen_pos(t_ent *ent, t_ent *pl);

#endif // ENTITY_INTERNAL_H 