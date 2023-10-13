/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:37:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 15:30:14 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBFILE_H
# define CUBFILE_H

# include "cub3d.h"

int		load_data(int fd);

t_bool	is_all_data_loaded(void);
char	*normed(char *line);
char	**parse_color_comp(char *line);

int		load_map(int fd);

t_bool	is_file_over(int fd);
void	set_player_dir(char c);
void	set_player_plane(char c);
t_mtile	**calloc_tiles(t_vec2i size);

int		check_map(void);

t_bool	**calloc_visited(t_vec2i size);
void	free_visited(t_bool	**visited, t_vec2i size);

char	*gnl_no_empty(int fd);

#endif // CUBFILE_H