/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:45:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 19:20:38 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "cub3d.h"
# include "animation.h"

typedef enum e_sp_type {barrel, ss}		t_sp_type;
typedef enum e_sp_state {idle, dead}	t_sp_state;

struct s_sprite
{
	t_vec2f	pos;
	t_anim	*curr_anim;

	t_anim	*idle_anim;
	t_anim	*die_anime;
};

int		new_sprite(t_vec2f pos, t_sp_type type);
void	play_anim(t_sprite *sp, t_anim *anim);

t_bool	is_sprite_sorted(t_sprite *a, t_sprite *b);
void	update_one_sprite(void *sp);
void	del_sprite(void *sp);

#endif // SPRITE_H