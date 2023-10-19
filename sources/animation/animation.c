/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:50:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 11:19:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "animation.h"
#include "error.h"

int	anim_from_path(t_anim *dest, char *const_path, int fcount, float s)
{
	char	path[100];
	int		i;

	ft_strlcpy(path, const_path, 100);
	i = 0;
	while (i < fcount)
	{
		path[ft_strlen(path) - 5] = i + '1';
		ft_strlcpy(cub_error()->texf, path, ERROR_FILES_MAX_LEN);
		dest->frames[i] = ctx_from_img(path);
		if (dest->frames[i] == NULL)
			return (set_error(ANIM_LOAD_ERROR), -1);
		clear_pixels(dest->frames[i], 0x00980088);
		fill_ctx(dest->frames[i], RED);
		i++;
	}
	dest->frame_count = fcount;
	dest->timer = new_timer(s);
	return (0);
}

t_ctx	*request_anim_frame(t_anim *anim)
{
	if (update_timer(&anim->timer) == true)
		return (anim->frames[anim->frame_count - 1]);
	return (anim->frames[
			(int)(((float)anim->frame_count / (float)anim->timer.target)
			* (float)anim->timer.n)]);
}

void	del_anim(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < anim->frame_count)
		free_context(anim->frames[i++]);
}
