/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:50:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 19:14:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "animation.h"
#include "error.h"

t_anim	*new_anim(char *const_path)
{
	char	path[100];
	int		i;
	t_anim	*anim;

	ft_strlcpy(path, const_path, 100);
	anim = ft_calloc(1, sizeof(t_anim));
	if (anim == NULL)
		return (set_error(MALLOC_ERROR), NULL);
	i = 0;
	while (i < ANIM_FRAME_NBR)
	{
		path[ft_strlen(path) - 5] = i + '1';
		ft_strlcpy(cub_error()->texf, path, ERROR_FILES_MAX_LEN);
		anim->frames[i] = ctx_from_img(path);
		if (anim->frames[i] == NULL)
			return (free_anim(anim), set_error(ANIM_LOAD_ERROR), NULL);
		clear_pixels(anim->frames[i], 0x00980088);
		i++;
	}
	return (anim);
}

void	free_anim(t_anim *anim)
{
	int	i;

	i = 0;
	if (anim == NULL)
		return ;
	while (i < ANIM_FRAME_NBR)
		free_context(anim->frames[i++]);
	free(anim);
}

void	update_anim(t_anim *anim)
{
	if (anim->counter < ANIM_FRAME_DELAY)
		return ((void)anim->counter++);
	anim->counter = 0;
	if (++anim->curr_index < ANIM_FRAME_NBR)
		anim->curr_frame = anim->frames[anim->curr_index];
}

void	reset_anim(t_anim *anim)
{
	anim->counter = 0;
	anim->curr_index = 0;
	anim->curr_frame = anim->frames[0];
}
