/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:37:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/12 21:35:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBFILE_H
# define CUBFILE_H

# include "cub3d.h"

int		load_data(int fd);

int		load_map(int fd);

t_bool	is_all_data_loaded(void);
char	*gnl_no_empty(int fd);
char	*normalized_line(char *line);
char	**split_color_comp(char *str);
int		add_line(char *line, t_list **list);
t_mtile	**calloc_tiles(t_vec2i size);
void	set_player_vec(t_vec2i pos, char dir);

#endif // CUBFILE_H