/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 18:05:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# define ANIM_FRAME_NBR 4
# define ANIM_FRAME_DELAY 7

# include "cub3d.h"

typedef struct s_anim
{
	t_ctx	*curr_frame;
	int		curr_index;
	t_ctx	*frames[ANIM_FRAME_NBR];
	int		counter;

}	t_anim;

t_anim	*new_anim(char *dir);
void	free_anim(t_anim *anim);
void	update_anim(t_anim *anim);
void	reset_anim(t_anim *anim);

#endif // ANIMATION_H