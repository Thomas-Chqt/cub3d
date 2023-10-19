/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:19:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 13:48:10 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hud.h"
#include "error.h"

int	setup_hud(t_hud **dest)
{
	t_hud	*hud;

	hud = ft_calloc(1, sizeof(t_hud));
	if (hud == NULL)
		return (set_error(MALLOC_ERROR), -1);
	if (anim_from_path(&hud->idle_anim,
			"resources/hud/idle/1.xpm", 1, 0.0f) != 0)
		return (free(hud), -1);
	if (anim_from_path(&hud->shoot_anim,
			"resources/hud/shoot/1.xpm", 8, 1.0f) != 0)
		return (clean_hud(hud), -1);
	hud->curr_anim = hud->idle_anim;
	*dest = hud;
	return (0);
}

void	clean_hud(t_hud *hud)
{
	if (hud == NULL)
		return ;
	del_anim(&hud->idle_anim);
	del_anim(&hud->shoot_anim);
	free(hud);
}
