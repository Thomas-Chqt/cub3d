/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:29:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 15:11:49 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

int	setup_entities(t_cub3d *cub)
{
	t_list	*cfents;
	t_ent	*new_ent;
	t_list	*node;

	cfents = get_entities_srt_pos(cub->cubf);
	while (cfents != NULL)
	{
		new_ent = new_ent_from_cfent((t_cfent *)cfents->data);
		if (new_ent == NULL)
			return (clean_entities(cub), set_error(MALLOC_ERROR), -1);
		if (ft_strchr("NSEW", ((t_cfent *)cfents->data)->id) != NULL)
			cub->p_ref = new_ent;
		node = ft_lstnew(new_ent);
		if (node == NULL)
			return (clean_entities(cub), free(new_ent),
				set_error(MALLOC_ERROR), -1);
		ft_lstadd_front(&cub->ent_lst, node);
		cfents = cfents->next;
	}
	return (0);
}

t_vec2f	ent_pos(t_ent *ent)
{
	return (ent->pos);
}

t_vec2f	ent_dir(t_ent *ent)
{
	return (ent->dir);
}

void	mov_ent(t_cubf *cubf, t_ent *ent, t_vec2f vec)
{
	t_vec2f	new_pos;

	new_pos = add_vf2vf2(ent->pos, vec);
	if (new_pos.x < ent->pos.x
		&& (is_out_map(cubf, (t_vec2i){new_pos.x - ENT_HBOX / 2, ent->pos.y})
		|| is_solid(cubf, (t_vec2i){new_pos.x - ENT_HBOX / 2, ent->pos.y})))
		ent->pos.x = ((int)ent->pos.x) + ENT_HBOX / 2;
	else if (is_out_map(cubf, (t_vec2i){new_pos.x + ENT_HBOX / 2, ent->pos.y})
		|| is_solid(cubf, (t_vec2i){new_pos.x + ENT_HBOX / 2, ent->pos.y}))
		ent->pos.x = ((int)ent->pos.x + 1) - ENT_HBOX / 2;
	else
		ent->pos.x = new_pos.x;
	if (new_pos.y < ent->pos.y
		&& (is_out_map(cubf, (t_vec2i){ent->pos.x, new_pos.y - ENT_HBOX / 2})
		|| is_solid(cubf, (t_vec2i){ent->pos.x, new_pos.y - ENT_HBOX / 2})))
		ent->pos.y = ((int)ent->pos.y) + ENT_HBOX / 2;
	else if (is_out_map(cubf, (t_vec2i){ent->pos.x, new_pos.y + ENT_HBOX / 2})
		|| is_solid(cubf, (t_vec2i){ent->pos.x, new_pos.y + ENT_HBOX / 2}))
		ent->pos.y = ((int)ent->pos.y + 1) - ENT_HBOX / 2;
	else
		ent->pos.y = new_pos.y;
}

void	clean_entities(t_cub3d *cub)
{
	ft_lstclear(&cub->ent_lst, &free_wrap);
}
