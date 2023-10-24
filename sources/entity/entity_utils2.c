/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:15:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 14:00:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

void	rot_to_player(t_ent *ent, t_ent *pl)
{
	t_vec2f	r_pos;
	float	vec_len;

	r_pos = sub_vf2vf2(pl->pos, ent->pos);
	vec_len = sqrtf(r_pos.x * r_pos.x + r_pos.y * r_pos.y);
	ent->dir = (t_vec2f){r_pos.x / vec_len, r_pos.y / vec_len};
}

void	update_screen_pos(t_ent *ent, t_ent *pl)
{
	t_vec2f	r_pos;
	float	inv_det;

	r_pos = sub_vf2vf2(ent->pos, pl->pos);
	inv_det = 1.0 / (pl->pla.x * pl->dir.y - pl->dir.x * pl->pla.y);
	ent->s_dep = inv_det * (-pl->pla.y * r_pos.x + pl->pla.x * r_pos.y);
	ent->s_pos = (t_vec2i){
		(int)((WIDTH / 2) * (1 + (inv_det * (pl->dir.y * r_pos.x - pl->dir.x
						* r_pos.y)) / ent->s_dep)),
		(HEIGHT / 2)};
}
