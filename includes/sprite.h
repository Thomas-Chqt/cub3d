/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:45:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 11:32:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "cub3d.h"
# include "animation.h"

typedef enum e_sp_type {barrel, ss}		t_sp_type;

typedef struct s_sprite
{
	t_sp_type	type;
	t_vec2f		pos;
	t_ctx		*img;

	t_anim		curr_anim;

	t_anim		idle_anim;
	t_anim		die_anim;

	int			hp;

}	t_sprite;

void		setup_sprites(t_cubf *cubf, t_list **anim_lst);
void		free_sprite(t_sprite *sp);

int			add_new_barrel_sprite(t_list **lst, t_vec2f pos);
int			add_new_ss_sprite(t_list **lst, t_vec2f pos);
t_bool		is_sp_closer(t_sprite *a, t_sprite *b, t_play *player);
void		sp_take_damage(t_sprite *sp, int amount);

#endif // SPRITE_H