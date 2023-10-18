/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:50:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 21:08:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "animation.h"
#include "error.h"

int	setup_anims(t_anims **dest)
{
	t_anims	*all_anims;

	all_anims = ft_calloc(1, sizeof(t_anims));
	if (all_anims == NULL)
		return (set_error(MALLOC_ERROR), -1);
	if (anim_from_path(&all_anims->barrel[idle],
			"resources/sprites/barrel/idle/ .xpm", 1, 0) != 0)
		return (clean_anims(all_anims), -1);
	if (anim_from_path(&all_anims->ss[idle],
			"resources/sprites/ss/idle/ .xpm", 1, 0) != 0)
		return (clean_anims(all_anims), -1);
	if (anim_from_path(&all_anims->ss[die],
			"resources/sprites/ss/die/ .xpm", 4, 0.6) != 0)
		return (clean_anims(all_anims), -1);
	*dest = all_anims;
	return (0);
}

t_ctx	*request_anim_frame(t_anim *anim)
{
	if (update_timer(&anim->timer) == true)
		return (anim->frames[anim->frame_count - 1]);
	return (anim->frames[(int)(((float)anim->frame_count / (float)anim->timer.target) * (float)anim->timer.n)]);
}

void	clean_anims(t_anims *anims)
{
	del_anim(anims->barrel[idle]);
	del_anim(anims->ss[idle]);
	del_anim(anims->ss[die]);
	free(anims);
}
