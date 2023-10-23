/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:52:04 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/23 15:52:30 by tchoquet         ###   ########.fr       */
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
