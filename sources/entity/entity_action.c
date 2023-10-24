/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:37:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 21:15:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

void	ent_shoot(t_ent *ent, t_list *ent_lst, t_cub3d *cub)
{
	t_ent	*hit;

	if (timer_status(ent->cooldown) < 1)
		return ;
	ent->curr_anim = ent->shoot_anim;
	ent->cooldown.n = 0;
	hit = entity_ray(ent, ent->dir, ent_lst, cub->cubf);
	if (hit == NULL)
		return ;
	ent_take_dmg(hit, ent->dmg, cub);
}

void	ent_take_dmg(t_ent *ent, int amount, t_cub3d *cub)
{
	if (ent->hp <= amount)
		ent->hp = 0;
	else
		ent->hp -= amount;
	if (ent->hp <= 0 && ent->die_anim.frames[0] != NULL)
	{
		ent->curr_anim = ent->die_anim;
	}
	if (is_alive(cub->p_ref) == false)
	{
		clean(cub);
		ft_putstr_fd("\033[0;31mGame Over\033[0m\n", STDOUT_FILENO);
		exit(0);
	}
	if (is_all_dead(cub->ent_lst, cub->p_ref))
	{
		clean(cub);
		ft_putstr_fd("\033[0;32mLevel Clear\033[0m\n", STDOUT_FILENO);
		exit(0);
	}
}
