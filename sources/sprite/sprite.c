/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:59:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 20:57:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sprite.h"
#include "error.h"
#include "player.h"

int	add_new_sprite(t_list **lst, t_sp_type type, t_vec2f pos)
{
	t_list	*node;

	node = ft_lstnew(NULL);
	if (node == NULL)
		return (set_error(MALLOC_ERROR), -1);
	if (type == barrel)
		node->data = new_barrel_sprite();
	if (type == ss)
		node->data = new_ss_sprite();
	if (node->data == NULL)
		return (free(node), -1);
	((t_sprite *)node->data)->pos = pos;
	ft_lstadd_front(lst, node);
	return (0);
}

t_bool	is_sp_closer(t_sprite *a, t_sprite *b, t_play *p)
{
	return ((((p->pos.x - a->pos.x) * (p->pos.x - a->pos.x)
				+ (p->pos.y - a->pos.y) * (p->pos.y - a->pos.y))
			>= ((p->pos.x - b->pos.x) * (p->pos.x - b->pos.x)
				+ (p->pos.y - b->pos.y) * (p->pos.y - b->pos.y)))
	);
}

void	play_idle_anim(t_sprite *sp, t_anims *anims)
{
	if (sp->type == barrel)
		sp->curr_anim = anims->barrel[idle];
	if (sp->type == ss)
		sp->curr_anim = anims->ss[idle];
}

void	play_anim(t_sprite *sp, t_anim_type type, t_anims *anims)
{
	if (sp->type == barrel)
		sp->curr_anim = anims->barrel[type];
	if (sp->type == ss)
		sp->curr_anim = anims->ss[type];
}

void	sp_take_damage(t_sprite *sp, int amount, t_anims *anims)
{
	if (sp->type == barrel || sp->hp <= 0)
		return ;
	sp->hp -= amount;
	if (sp->hp <= 0)
		play_anim(sp, die, anims);
}
