/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 20:04:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "cub3d.h"
# include "timer.h"

# define ANIM_MAX_FRAME 20

typedef enum e_anim_type {idle = 0, die = 1}	t_anim_type;

typedef struct s_anim
{
	t_ctx	*frames[ANIM_MAX_FRAME];
	int		frame_count;
	t_timer	timer;

}	t_anim;

struct s_anims
{
	t_anim	barrel[2];
	t_anim	ss[2];
};

int		setup_anims(t_anims **dest);
t_ctx	*request_anim_frame(t_anim *anim);
void	clean_anims(t_anims *anims);

int		anim_from_path(t_anim *dest, char *const_path, int fcount, float s);
void	del_anim(t_anim anim);

#endif // ANIMATION_H