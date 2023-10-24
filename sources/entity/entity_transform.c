/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:13:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 15:32:10 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

void	mov_ent(t_cubf *cubf, t_ent *ent, t_vec2f vec)
{
	t_vec2f	new_pos;

	new_pos = add_vf2vf2(ent->pos, vec);
	if (new_pos.x < ent->pos.x && get_mtile(cubf, (t_vec2i){
			new_pos.x - ENT_HBOX / 2, ent->pos.y}) >= 0)
		ent->pos.x = ((int)ent->pos.x) + ENT_HBOX / 2;
	else if (get_mtile(cubf, (t_vec2i){
			new_pos.x + ENT_HBOX / 2, ent->pos.y}) >= 0)
		ent->pos.x = ((int)ent->pos.x + 1) - ENT_HBOX / 2;
	else
		ent->pos.x = new_pos.x;
	if (new_pos.y < ent->pos.y && get_mtile(cubf, (t_vec2i){
			ent->pos.x, new_pos.y - ENT_HBOX / 2}) >= 0)
		ent->pos.y = ((int)ent->pos.y) + ENT_HBOX / 2;
	else if (get_mtile(cubf, (t_vec2i){
			ent->pos.x, new_pos.y + ENT_HBOX / 2}) >= 0)
		ent->pos.y = ((int)ent->pos.y + 1) - ENT_HBOX / 2;
	else
		ent->pos.y = new_pos.y;
}

void	rot_ent(t_ent *ent, float rad)
{
	ent->dir = rot_vf2(ent->dir, rad);
	ent->pla = rot_vf2(ent->pla, rad);
}
