/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:45:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/15 17:24:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "cub3d.h"

typedef struct s_sprite
{
	t_vec2f	pos;
	t_ctx	*img;

}	t_sprite;

int		new_sprite(t_vec2f pos, t_ctx *img);
void	free_sprites(void);
void	sort_sprites(void);

t_bool	is_sprite_sorted(t_sprite *a, t_sprite *b);
void	del_sprite(t_sprite *sp);

#endif // SPRITE_H