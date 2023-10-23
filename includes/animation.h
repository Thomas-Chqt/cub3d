/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:59:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/23 14:19:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "timer.h"

# define ANIM_MAX_FRAME 20

typedef struct s_anim
{
	t_ctx	*frames[ANIM_MAX_FRAME];
	int		frame_count;
	t_timer	timer;

}	t_anim;

t_anim	new_anim(char *const_path, int fcount, float duration);
t_ctx	*request_anim_frame(t_anim *anim);
void	del_anim(t_anim anim);

#endif // ANIMATION_H