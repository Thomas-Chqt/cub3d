/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:13:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 17:44:40 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

void	rot_ent(t_ent *ent, float rad)
{
	ent->dir = rot_vf2(ent->dir, rad);
	ent->pla = rot_vf2(ent->pla, rad);
}

t_vec2f	ent_pla(t_ent *ent)
{
	return (ent->pla);
}
