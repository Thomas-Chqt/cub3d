/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:35:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 16:52:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBFILE_INTERNAL_H
# define CUBFILE_INTERNAL_H

# include "cubfile.h"
# include "error.h"

typedef enum e_map_tile { empty = -1, wall = 1 }	t_mtile;

typedef struct s_cubf_data
{
	t_ctx		*no_tex;
	t_ctx		*so_tex;
	t_ctx		*we_tex;
	t_ctx		*ea_tex;

	t_uint32	c_color;
	t_uint32	f_color;

}	t_cubf_data;

typedef struct s_cubf_map
{
	t_mtile	**tiles;
	t_vec2i	size;

	t_list	*entity_lst;
	t_cfent	*player;

}	t_cubf_map;

struct s_cubf
{
	t_cubf_data	data;
	t_cubf_map	map;
};

//----DATA----
int		load_data(t_cubf_data *data, int fd);
void	clean_data(t_cubf_data *data);

t_bool	is_all_loaded(t_cubf_data *cubf);
char	*normed(char *line);
char	**parse_color_comp(char *line);

//-----MAP----
int		load_map(t_cubf_map *map, int fd);
void	clean_map(t_cubf_map *map);

t_bool	is_file_over(int fd);
t_mtile	**calloc_tiles(t_vec2i size);
void	free_all(char *line, t_list **line_lst, t_cubf_map *map);
t_cfent	*add_ent(t_list **list, t_vec2i pos, char id);

//----CHECK----
int		check_map(t_cubf *cubf);

t_bool	**calloc_visited(t_vec2i size);
void	free_visited(t_bool	**visited, t_vec2i size);

//----UTILS----
char	*gnl_no_empty(int fd);

#endif // CUBFILE_INTERNAL_H