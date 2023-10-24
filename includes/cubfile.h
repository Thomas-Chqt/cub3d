/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:37:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 16:09:49 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBFILE_H
# define CUBFILE_H

# include "cub3d.h"

typedef enum e_hit_side { no = -2, so = -1, ea = 1, we = 2 }	t_side;

typedef enum e_map_tile {
	open_door = -2,
	empty = -1,
	out_map = 0,
	wall = 1,
	close_door = 2
}	t_mtile;

typedef struct s_cubf_ent
{
	t_vec2i	pos;
	char	id;

}	t_cfent;

int			parse_cubfile(t_cubf **dest, char *file);
t_list		*get_entities_srt_pos(t_cubf *cubf);
t_mtile		get_mtile(t_cubf *cubf, t_vec2i pos);
void		toggle_door(t_cubf *cubf, t_vec2i pos);
void		clean_cubfile(t_cubf *cubf);

t_ctx		*get_tex(t_cubf *cubf, t_side side);
t_ctx		*get_do_tex(t_cubf *cubf);
t_uint32	get_c_color(t_cubf *cubf);
t_uint32	get_f_color(t_cubf *cubf);

#endif // CUBFILE_H