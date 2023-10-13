/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:40:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 21:38:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

typedef struct s_wall_data
{
	int		wall_h;
	int		wall_srt;
	int		wall_end;
	float	wall_x;
	t_ctx	*tex;

}	t_wall;

t_vec2i		mtos(t_vec2f vect, t_vec2i mmap_pos);
t_wall		init_wall_data(t_dres dda_res);
t_uint32	tex_px(t_wall wall_data, t_vec2i pos);

#endif // RENDER_H