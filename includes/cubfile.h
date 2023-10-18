/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:37:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 18:20:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBFILE_H
# define CUBFILE_H

# include "cub3d.h"

typedef enum e_map_tile { empty = -1, wall = 1 }	t_mtile;

struct s_cubf
{
	t_ctx		*no_tex;
	t_ctx		*so_tex;
	t_ctx		*we_tex;
	t_ctx		*ea_tex;

	t_uint32	c_color;
	t_uint32	f_color;

	t_mtile		**map;
	t_vec2i		m_size;

	t_vec2i		p_srt_pos;
	char		p_srt_dir;
	t_list		*sp_lst;
};

int		parse_cubfile(t_cubf **dest, char *file);
void	clean_cubfile(t_cubf *cubf);

int		load_data(t_cubf *cubf, int fd);

t_bool	is_all_data_loaded(t_cubf *cubf);
char	*normed(char *line);
char	**parse_color_comp(char *line);

int		load_map(t_cubf *cubf, int fd);

t_bool	is_file_over(int fd);
t_mtile	**calloc_tiles(t_vec2i size);

int		check_map(t_cubf *cubf);

t_bool	**calloc_visited(t_vec2i size);
void	free_visited(t_bool	**visited, t_vec2i size);

char	*gnl_no_empty(int fd);
void	free_cubf_textures(t_cubf *cubf);

#endif // CUBFILE_H