/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:16:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 13:30:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_INTERNAL_H
# define DDA_INTERNAL_H

# include "dda.h"
# include "cubfile.h"
# include "entity.h"

typedef struct s_wall_ray_res
{
	float		len;
	t_stripe	vstripe;

}	t_wray_res;

typedef struct s_entity_ray_res
{
	t_ent	*hit;
	float	len;

}	t_eray_res;

typedef struct s_dda_data
{
	t_vec2f	srt;
	t_vec2f	dir;

	t_vec2i	tstep;
	t_vec2i	tcurr;

	t_vec2f	lstep;
	t_vec2f	lcurr;

	t_ctx	*v_tex;
	t_ctx	*h_tex;

	t_ctx	*c_tex;

	float	wall_x;

	t_ent	*ent_src;

}	t_dda_data;

t_dda_data	make_dda_data(t_vec2f srt, t_vec2f dir, t_cubf *cubf);
t_bool		is_ent_hit(t_eray_res *res, t_dda_data *da, t_list *ents);

#endif // DDA_INTERNAL_H