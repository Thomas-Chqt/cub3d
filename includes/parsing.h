/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:02:40 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/05 16:31:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

int		parse_cubf_data(int fd, t_cubf *cubf);

t_bool	is_data_all_parsed(t_cubf *cubf);
void	goto_line_start(char **line_ptr);
void	normalize_line(char **line_ptr);
t_bool	is_color_comp_sep(char c);

int		parse_cubf_map(int fd, t_cubf *cubf);

void	skip_empty_lines(int fd, char **line);
int		normalize_map_line(char **line_ptr);
t_tile	**calloc_tiles(t_whi size);
t_tile	to_tile(char c);

int		check_cubf_map(t_cubf *cubf);

t_bool	**calloc_visited(t_whi size);
void	free_visited(t_bool	**visited, t_whi size);

#endif // PARSING_H