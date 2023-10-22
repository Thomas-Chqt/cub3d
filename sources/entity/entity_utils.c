/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:36:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 13:03:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

static t_vec2f	char_to_dir_vec(char c);
static t_vec2f	char_to_plane_vec(char c);

t_ent	*new_ent_from_cfent(t_cfent *ent)
{
	t_ent	*new_ent;

	new_ent = ft_calloc(1, sizeof(t_ent));
	if (new_ent == NULL)
		return (NULL);
	new_ent->pos = add_vf2vf2(vi2tovf2(ent->pos), (t_vec2f){0.5, 0.5});
	new_ent->dir = char_to_dir_vec(ent->id);
	new_ent->pla = char_to_plane_vec(ent->id);
	return (new_ent);
}

static t_vec2f	char_to_dir_vec(char c)
{
	if (c == 'S')
		return ((t_vec2f){.x = 0.0f, .y = 1.0f});
	if (c == 'E')
		return ((t_vec2f){.x = 1.0f, .y = 0.0f});
	if (c == 'W')
		return ((t_vec2f){.x = -1.0f, .y = 0.0f});
	return ((t_vec2f){.x = 0.0f, .y = -1.0f});
}

static t_vec2f	char_to_plane_vec(char c)
{
	if (c == 'N')
		return ((t_vec2f){.x = tanf(torad((float)FOV / 2.0f)), .y = 0.0f});
	if (c == 'S')
		return ((t_vec2f){.x = -tanf(torad((float)FOV / 2.0f)), .y = 0.0f});
	if (c == 'E')
		return ((t_vec2f){.x = 0.0f, .y = tanf(torad((float)FOV / 2))});
	if (c == 'W')
		return ((t_vec2f){.x = 0.0f, .y = -tanf(torad((float)FOV / 2))});
	return ((t_vec2f){0, 0});
}
