/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:52:04 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 14:28:40 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

t_vec2f	ent_pos(t_ent *ent)
{
	return (ent->pos);
}

t_vec2f	ent_dir(t_ent *ent)
{
	return (ent->dir);
}

t_vec2f	ent_pla(t_ent *ent)
{
	return (ent->pla);
}

t_bool	is_alive(t_ent *ent)
{
	return (ent->hp > 0);
}

t_bool	is_all_dead(t_list *ent_lst, t_ent *player)
{
	t_list	*curr;

	curr = ent_lst;
	while (curr != NULL)
	{
		if ((t_ent *)curr->data != player && is_alive((t_ent *)curr->data))
			return (false);
		curr = curr->next;
	}
	return (true);
}
