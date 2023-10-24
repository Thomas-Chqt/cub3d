/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:29:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 14:08:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

int	setup_entities(t_list **lst, t_cubf *cubf, t_ent **p_ref)
{
	t_list	*curr;
	t_ent	*new_ent;
	t_list	*node;

	curr = get_entities_srt_pos(cubf);
	while (curr != NULL)
	{
		if (create_ent(&new_ent, ((t_cfent *)curr->data)) != 0)
			return (ft_lstclear(lst, (t_a)clean_entity),
				clean_entity(*p_ref), -1);
		if (ft_strchr("NSEW", ((t_cfent *)curr->data)->id) != NULL)
			*p_ref = new_ent;
		node = ft_lstnew(new_ent);
		if (node == NULL)
			return (ft_lstclear(lst, (t_a)clean_entity),
				clean_entity(*p_ref), clean_entity(new_ent),
				set_error(MALLOC_ERROR), -1);
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
	t_ent	*hit;

	ent->img = request_anim_frame(&ent->curr_anim);
	update_timer(&ent->cooldown);
	if (ent == cub->p_ref)
		return ;
	update_screen_pos(ent, cub->p_ref);
	if (is_alive(ent) == false)
		return ;
	if (timer_status(ent->reaction) == 0)
	{
		rot_to_player(ent, cub->p_ref);
		hit = entity_ray(ent, ent->dir, cub->ent_lst, cub->cubf);
		if (hit != cub->p_ref)
			return ;
	}
	else if (timer_status(ent->reaction) == 1)
	{
		ent_shoot(ent, cub->ent_lst, cub->cubf);
		ent->reaction.n = 0;
		return ;
	}
	update_timer(&ent->reaction);
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

	if (ent->s_dep <= 0)
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
