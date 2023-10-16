/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:59:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/16 20:02:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sprite.h"
#include "error.h"

int	new_sprite(t_vec2f pos, t_ctx *img)
{
	t_list	*new_node;

	if (img == NULL)
		return (set_error(MALLOC_ERROR), -1);
	new_node = ft_lstnew(NULL);
	if (new_node == NULL)
		return (set_error(MALLOC_ERROR), -1);
	new_node->data = malloc(sizeof(t_sprite));
	if (new_node->data == NULL)
		return (free(new_node), set_error(MALLOC_ERROR), -1);
	((t_sprite *)new_node->data)->pos = pos;
	((t_sprite *)new_node->data)->img = img;
	clear_pixels(((t_sprite *)new_node->data)->img, BLACK);
	if (ctx_vstripe(((t_sprite *)new_node->data)->img, 0).px == NULL)
		return (del_sprite((t_sprite *)new_node->data),
			free(new_node), set_error(MALLOC_ERROR), -1);
	ft_lstadd_front(&cub3d()->sprite_lst, new_node);
	return (0);
}

void	free_sprites(void)
{
	ft_lstclear(&cub3d()->sprite_lst, (void (*)(void *)) & del_sprite);
}

void	sort_sprites(void)
{
	lst_qcksort(cub3d()->sprite_lst,
		(t_bool (*)(void *, void *)) & is_sprite_sorted);
}
