/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:12:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 20:53:09 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sprite.h"
#include "error.h"

t_sprite	*new_barrel_sprite(void)
{
	t_sprite	*sp;

	sp = ft_calloc(1, sizeof(t_sprite));
	if (sp == NULL)
		return (set_error(MALLOC_ERROR), NULL);
	sp->type = barrel;
	sp->img = NULL;
	sp->hp = 100;
	return (sp);
}

t_sprite	*new_ss_sprite(void)
{
	t_sprite	*sp;

	sp = ft_calloc(1, sizeof(t_sprite));
	if (sp == NULL)
		return (set_error(MALLOC_ERROR), NULL);
	sp->type = ss;
	sp->img = NULL;
	sp->hp = 100;
	return (sp);
}
