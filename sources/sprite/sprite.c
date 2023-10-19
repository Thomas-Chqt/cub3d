/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:59:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 13:18:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "sprite.h"
#include "error.h"
#include "cubfile.h"

void	setup_sprites(t_cubf *cubf, t_list **anim_lst)
{
	*anim_lst = cubf->sp_lst;
	cubf->sp_lst = NULL;
}

void	free_sprite(t_sprite *sp)
{
	if (sp == NULL)
		return ;
	del_anim(&sp->idle_anim);
	del_anim(&sp->die_anim);
	free(sp);
}
