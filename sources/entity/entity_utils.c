/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:36:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/23 20:00:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

int	create_ent(t_ent **dest, t_cfent *cfent)
{
	*dest = ft_calloc(1, sizeof(t_ent));
	if (*dest == NULL)
		return (set_error(MALLOC_ERROR), -1);
	(*dest)->pos = add_vf2vf2(vi2tovf2(cfent->pos), (t_vec2f){0.5, 0.5});
	if (cfent->id == 'N')
		(*dest)->dir = (t_vec2f){.x = 0.0f, .y = -1.0f};
	if (cfent->id == 'S')
		(*dest)->dir = (t_vec2f){.x = 0.0f, .y = 1.0f};
	if (cfent->id == 'E')
		(*dest)->dir = (t_vec2f){.x = 1.0f, .y = 0.0f};
	if (cfent->id == 'W')
		(*dest)->dir = (t_vec2f){.x = -1.0f, .y = 0.0f};
	(*dest)->pla = mul_vf2f(rot_vf2((*dest)->dir, M_PI_2),
			tanf(torad(FOV / 2.0f)));
	if (cfent->id == 'X' && fill_ss_anim(*dest) != 0)
		return (clean_entity(*dest), *dest = NULL, -1);
	if (ft_strchr("NSEW", cfent->id) != NULL && fill_hud_anim(*dest) != 0)
		return (clean_entity(*dest), *dest = NULL, -1);
	fill_setup_data(*dest, cfent->id);
	return (0);
}

t_bool	is_ent_closer(t_ent *a, t_ent *b, t_ent *pl)
{
	return ((((pl->pos.x - a->pos.x) * (pl->pos.x - a->pos.x)
				+ (pl->pos.y - a->pos.y) * (pl->pos.y - a->pos.y))
			>= ((pl->pos.x - b->pos.x) * (pl->pos.x - b->pos.x)
				+ (pl->pos.y - b->pos.y) * (pl->pos.y - b->pos.y)))
	);
}

int	fill_ss_anim(t_ent *ent)
{
	ent->idle_anim = new_anim("resources/anims/ss_idle/1.xpm", 1, 0);
	if (ent->idle_anim.frames[0] == NULL)
		return (-1);
	ent->die_anim = new_anim("resources/anims/ss_die/1.xpm", 4, 0.6);
	if (ent->die_anim.frames[0] == NULL)
		return (del_anim(ent->idle_anim), -1);
	return (0);
}

int	fill_hud_anim(t_ent *ent)
{
	ent->idle_anim = new_anim("resources/anims/hud_idle/1.xpm", 1, 0);
	if (ent->idle_anim.frames[0] == NULL)
		return (-1);
	ent->shoot_anim = new_anim("resources/anims/hud_shoot/1.xpm", 8, 1);
	if (ent->shoot_anim.frames[0] == NULL)
		return (del_anim(ent->idle_anim), -1);
	return (0);
}

void	fill_setup_data(t_ent *ent, char id)
{
	if (ft_strchr("NSEW", id) != NULL)
	{
		ent->hp = 100;
		ent->dmg = 100;
	}
	if (id == 'X')
	{
		ent->hp = 100;
		ent->dmg = 30;
	}
	ent->curr_anim = ent->idle_anim;
}
