/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:37:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 17:51:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBFILE_H
# define CUBFILE_H

# include "cub3d.h"

typedef enum e_hit_side { no = -2, so = -1, ea = 1, we = 2 }	t_side;

typedef struct s_cubf_ent
{
	t_vec2i	pos;
	char	id;

}	t_cfent;

int			parse_cubfile(t_cubf **dest, char *file);

t_list		*get_entities_srt_pos(t_cubf *cubf);
t_ctx		*get_tex(t_cubf *cubf, t_side side);
t_uint32	get_c_color(t_cubf *cubf);
t_uint32	get_f_color(t_cubf *cubf);

t_bool		is_out_map(t_cubf *cubf, t_vec2i pos);
t_bool		is_solid(t_cubf *cubf, t_vec2i pos);

void		clean_cubfile(t_cubf *cubf);

#endif // CUBFILE_H