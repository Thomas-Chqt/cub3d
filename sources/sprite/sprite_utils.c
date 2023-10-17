/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:12:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 17:45:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sprite.h"

t_bool	is_sprite_sorted(t_sprite *a, t_sprite *b)
{
	return (
		(((cub3d()->p_pos.x - a->pos.x)
				* (cub3d()->p_pos.x - a->pos.x)
				+ (cub3d()->p_pos.y - a->pos.y)
				* (cub3d()->p_pos.y - a->pos.y))
			>= ((cub3d()->p_pos.x - b->pos.x)
				* (cub3d()->p_pos.x - b->pos.x)
				+ (cub3d()->p_pos.y - b->pos.y)
				* (cub3d()->p_pos.y - b->pos.y)))
	);
}

void	update_one_sprite(void *sp)
{
	update_anim(((t_sprite *)sp)->curr_anim);
}

void	del_sprite(void *sp)
{
	free_anim(((t_sprite *)sp)->idle_anim);
	free_anim(((t_sprite *)sp)->die_anime);
	free(sp);
}
