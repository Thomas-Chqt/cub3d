/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:29:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 13:00:51 by tchoquet         ###   ########.fr       */
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

void	clean_entities(t_cub3d *cub)
{
	ft_lstclear(&cub->ent_lst, &free_wrap);
}
