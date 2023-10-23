/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:29:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/23 20:07:51 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

int	setup_entities(t_list **lst, t_cubf *cubf, t_ent **p_ref)
{
	t_list	*curr;
	t_list	*node;

	curr = get_entities_srt_pos(cubf);
	while (curr != NULL)
	{
		node = ft_lstnew(NULL);
		if (node == NULL)
			return (ft_lstclear(lst, (t_a)clean_entity),
				set_error(MALLOC_ERROR), -1);
		if (create_ent((t_ent **)&node->data, ((t_cfent *)curr->data)) != 0)
			return (ft_lstclear(lst, (t_a)clean_entity), free(node), -1);
		if (ft_strchr("NSEW", ((t_cfent *)curr->data)->id) != NULL)
			*p_ref = (t_ent *)node->data;
		ft_lstadd_front(lst, node);
		curr = curr->next;
	}
	return (0);
}

void	clean_entity(t_ent *ent)
{
	del_anim(ent->idle_anim);
	del_anim(ent->die_anim);
	del_anim(ent->shoot_anim);
	free(ent);
}

void	entity_loop(t_ent *ent, t_cub3d *cub)
{
	t_vec2f	r_pos;
	float	inv_det;

	ent->img = request_anim_frame(&ent->curr_anim);
	r_pos = sub_vf2vf2(ent->pos, cub->p_ref->pos);
	inv_det = 1.0 / (cub->p_ref->pla.x * cub->p_ref->dir.y
			- cub->p_ref->dir.x * cub->p_ref->pla.y);
	ent->s_dep = inv_det * (-cub->p_ref->pla.y * r_pos.x
			+ cub->p_ref->pla.x * r_pos.y);
	ent->s_pos = (t_vec2i){(int)((WIDTH / 2) * (1 + (inv_det
					* (cub->p_ref->dir.y * r_pos.x - cub->p_ref->dir.x
						* r_pos.y)) / ent->s_dep)), (HEIGHT / 2)};
}

void	sort_entities(t_list *lst, t_ent *player)
{
	lst_qcksort_data(lst, (t_c)is_ent_closer, player);
}

void	render_entity(t_ent *ent, t_cub3d *cub)
{
	t_vec2i	ent_sz;
	int		scree_x;
	float	tex_x;
	float	tex_step;

	if (ent == cub->p_ref || ent->s_dep <= 0)
		return ;
	ent_sz = (t_vec2i){ft_abs((int)(HEIGHT / (ent->s_dep))),
		ft_abs((int)(HEIGHT / (ent->s_dep)))};
	tex_step = (float)ctx_size(ent->img).x / (float)ent_sz.x;
	scree_x = ent->s_pos.x - (ent_sz.x / 2);
	tex_x = 0;
	while (scree_x < WIDTH && scree_x < ent->s_pos.x + (ent_sz.x / 2))
	{
		if (scree_x >= 0 && ent->s_dep < cub->wall_dist[scree_x])
		{
			draw_vstripe(back_ctx(), ctx_vstripe(ent->img, (int)tex_x),
				(t_vec2i){scree_x, ent->s_pos.y - (ent_sz.y / 2)},
				(t_vec2i){scree_x, ent->s_pos.y + (ent_sz.y / 2)});
		}
		scree_x++;
		tex_x += tex_step;
	}
}
