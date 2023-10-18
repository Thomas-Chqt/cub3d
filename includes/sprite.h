/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:45:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 20:54:57 by tchoquet         ###   ########.fr       */
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

	int			hp;

}	t_sprite;

int			add_new_sprite(t_list **lst, t_sp_type type, t_vec2f pos);
t_bool		is_sp_closer(t_sprite *a, t_sprite *b, t_play *p);
void		play_idle_anim(t_sprite *sp, t_anims *anims);
void		play_anim(t_sprite *sp, t_anim_type type, t_anims *anims);
void		sp_take_damage(t_sprite *sp, int amount, t_anims *anims);

t_sprite	*new_barrel_sprite(void);
t_sprite	*new_ss_sprite(void);

#endif // SPRITE_H