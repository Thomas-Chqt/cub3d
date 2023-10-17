/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:59:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 18:34:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sprite.h"
#include "error.h"

int	new_sprite(t_vec2f pos, t_sp_type type)
{
	t_list		*new_node;
	t_sprite	*sp;

	new_node = ft_lstnew(NULL);
	if (new_node == NULL)
		return (set_error(MALLOC_ERROR), -1);
	new_node->data = malloc(sizeof(t_sprite));
	if (new_node->data == NULL)
		return (ft_lstclear(&new_node, &del_sprite),
			set_error(MALLOC_ERROR), -1);
	sp = (t_sprite *)new_node->data;
	sp->pos = pos;
	if (type == ss)
	{
		sp->idle_anim = new_anim("resources/sprites/ss/idle/X.xpm");
		sp->die_anime = new_anim("resources/sprites/ss/die/X.xpm");
		if (sp->idle_anim == NULL || sp->die_anime == NULL)
			return (ft_lstclear(&new_node, &del_sprite), -1);
	}
	play_anim(sp, sp->idle_anim);
	ft_lstadd_front(&cub3d()->sprite_lst, new_node);
	return (0);
}

void	play_anim(t_sprite *sp, t_anim *anim)
{
	sp->curr_anim = anim;
	reset_anim(sp->curr_anim);
}

void	sort_sprites(void)
{
	lst_qcksort(cub3d()->sprite_lst,
		(t_bool (*)(void *, void *)) & is_sprite_sorted);
}

void	update_sprites(void)
{
	ft_lstiter(cub3d()->sprite_lst, &update_one_sprite);
}

void	free_sprites(void)
{
	ft_lstclear(&cub3d()->sprite_lst, &del_sprite);
}
