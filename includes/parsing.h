/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:02:40 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/03 18:00:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

# define NO_PARSED_FLAG		0b000001
# define SO_PARSED_FLAG		0b000010
# define WE_PARSED_FLAG		0b000100
# define EA_PARSED_FLAG		0b001000
# define F_PARSED_FLAG		0b010000
# define C_PARSED_FLAG		0b100000
# define ALL_PARSED_FLAG	0b111111

int		parse_data(int fd, t_cubfile *cub);
int		parse_next_data(int fd, t_cubfile *cub);

int		parse_no_text(char *line, t_cubfile *cub);
int		parse_so_text(char *line, t_cubfile *cub);
int		parse_we_text(char *line, t_cubfile *cub);
int		parse_ea_text(char *line, t_cubfile *cub);
int		parse_f_col(char *line, t_cubfile *cub);
int		parse_c_col(char *line, t_cubfile *cub);

int		parse_map(int fd, t_cubfile *cub);

void	normalize_line(char *line);
t_bool	is_valid_map_line(char *line);
t_tile	to_tile(char c);

int		check_map(t_cubfile *cub);

#endif // PARSING_H