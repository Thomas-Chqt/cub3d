/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 11:22:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "cub3d.h"
# include "timer.h"

# define ANIM_MAX_FRAME 20

typedef struct s_anim
{
	t_ctx	*frames[ANIM_MAX_FRAME];
	int		frame_count;
	t_timer	timer;

}	t_anim;

int		anim_from_path(t_anim *dest, char *const_path, int fcount, float s);
t_ctx	*request_anim_frame(t_anim *anim);
void	del_anim(t_anim *anim);

#endif // ANIMATION_H