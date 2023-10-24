/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:18:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 12:53:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation_internal.h"

t_anim	new_anim(char *const_path, int fcount, float duration)
{
	t_anim	anim;
	int		i;
	char	path[100];

	ft_strlcpy(path, const_path, 100);
	i = 0;
	anim.frame_count = fcount;
	while (i < fcount)
	{
		path[ft_strlen(path) - 5] = i + '1';
		set_error_texf(path);
		anim.frames[i] = ctx_from_img(path);
		if (anim.frames[i] == NULL)
			return (del_anim(anim), set_error(ANIM_LOAD_ERROR), (t_anim){});
		clear_pixels(anim.frames[i], 0x00980088);
		i++;
	}
	anim.timer = new_timer(duration);
	return (anim);
}

t_ctx	*request_anim_frame(t_anim *anim)
{
	t_ctx	*frame;

	frame = anim->frames[
		(int)(((float)(anim->frame_count - 1)) * timer_status(anim->timer))
	];
	update_timer(&anim->timer);
	return (frame);
}

void	del_anim(t_anim anim)
{
	int	i;

	i = 0;
	while (i < anim.frame_count)
	{
		free_context(anim.frames[i]);
		anim.frames[i] = NULL;
		i++;
	}
}
