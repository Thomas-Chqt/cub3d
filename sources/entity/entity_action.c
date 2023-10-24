/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:37:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 13:55:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

void	ent_shoot(t_ent *ent, t_list *ent_lst, t_cubf *cubf)
{
	t_ent	*hit;

	if (timer_status(ent->cooldown) < 1)
		return ;
	ent->curr_anim = ent->shoot_anim;
	ent->cooldown.n = 0;
	hit = entity_ray(ent, ent->dir, ent_lst, cubf);
	if (hit == NULL)
		return ;
	ent_take_dmg(hit, ent->dmg);
}

void	ent_take_dmg(t_ent *ent, int amount)
{
	if (ent->hp <= amount)
		ent->hp = 0;
	else
		ent->hp -= amount;
	if (ent->hp <= 0 && ent->die_anim.frames[0] != NULL)
		ent->curr_anim = ent->die_anim;
}
