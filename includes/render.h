/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:40:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/16 18:05:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "sprite.h"

typedef struct s_wall_data
{
	int			wall_srt;
	int			wall_end;
	t_stripe	stripe;

}	t_wall;

t_vec2i		mtomm(t_vec2f vect, t_vec2i mmap_pos);
t_wall		init_wall_data(t_dres dda_res);
t_vec2i		transform_sppos(t_sprite *sp, float *dist);

#endif // RENDER_H