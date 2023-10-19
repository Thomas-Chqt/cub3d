/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:27:20 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 13:39:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sprite.h"
#include "error.h"
#include "cubfile.h"
#include "player.h"

int	add_new_barrel_sprite(t_list **lst, t_vec2f pos)
{
	t_list		*node;
	t_sprite	*sp;

	sp = ft_calloc(1, sizeof(t_sprite));
	if (sp == NULL)
		return (set_error(MALLOC_ERROR), -1);
	node = ft_lstnew(sp);
	if (node == NULL)
		return (free(sp), set_error(MALLOC_ERROR), -1);
	sp->type = barrel;
	sp->pos = pos;
	sp->hp = 100;
	if (anim_from_path(&sp->idle_anim,
			"resources/sprites/barrel/idle/1.xpm", 1, 0) != 0)
		return (free(node), free_sprite(sp), -1);
	sp->curr_anim = sp->idle_anim;
	ft_lstadd_front(lst, node);
	return (0);
}

int	add_new_ss_sprite(t_list **lst, t_vec2f pos)
{
	t_list		*node;
	t_sprite	*sp;

	sp = ft_calloc(1, sizeof(t_sprite));
	if (sp == NULL)
		return (set_error(MALLOC_ERROR), -1);
	node = ft_lstnew(sp);
	if (node == NULL)
		return (free(sp), set_error(MALLOC_ERROR), -1);
	sp->type = ss;
	sp->pos = pos;
	sp->hp = 100;
	if (anim_from_path(&sp->idle_anim,
			"resources/sprites/ss/idle/1.xpm", 1, 0) != 0)
		return (free(node), free_sprite(sp), -1);
	if (anim_from_path(&sp->die_anim,
			"resources/sprites/ss/die/1.xpm", 4, 0.6) != 0)
		return (free(node), free_sprite(sp), -1);
	sp->curr_anim = sp->idle_anim;
	ft_lstadd_front(lst, node);
	return (0);
}

t_bool	is_sp_closer(t_sprite *a, t_sprite *b, t_play *player)
{
	return ((((player->pos.x - a->pos.x)
				* (player->pos.x - a->pos.x)
				+ (player->pos.y - a->pos.y)
				* (player->pos.y - a->pos.y))
			>= ((player->pos.x - b->pos.x)
				* (player->pos.x - b->pos.x)
				+ (player->pos.y - b->pos.y)
				* (player->pos.y - b->pos.y)))
	);
}

void	sp_take_damage(t_sprite *sp, int amount)
{
	if (sp->type == barrel || sp->hp <= 0)
		return ;
	sp->hp -= amount;
	if (sp->hp <= 0)
		sp->curr_anim = sp->die_anim;
}
