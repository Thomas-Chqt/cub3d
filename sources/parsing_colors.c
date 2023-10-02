/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:21:28 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/02 21:21:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_bool	is_sep(char c);
static int		parse_rgb(t_uint32 *des, char **rgb);

int	parse_f_col(char *line, t_cubfile *cub)
{
	t_uint64	i;
	char		**splited_str;
	int			ret_val;

	i = 0;
	while (is_whitespace(line[i]) == true)
		i++;
	if (ft_strncmp(line + i, "F", 1) != 0)
		return (PARSING_ERROR);
	splited_str = str_split_func(line + i + 1, &is_sep);
	if (splited_str == NULL)
		return (cub_perror("malloc error"), MALLOC_ERROR);
	if (arrstr_len(splited_str) != 3)
		return (free_splited_str(splited_str),
			cub_perror_file("unreconized line"), FATAL_PARSING_ERROR);
	if ((cub->parsed_flags & F_PARSED_FLAG) != 0)
		return (cub_perror_file("multiple definition of F color"),
			MULTIPLE_DEF_ERROR);
	ret_val = parse_rgb(&cub->f_col, splited_str);
	if (ret_val == 0)
		cub->parsed_flags |= F_PARSED_FLAG;
	return (ret_val);
}

int	parse_c_col(char *line, t_cubfile *cub)
{
	t_uint64	i;
	char		**splited_str;
	int			ret_val;

	i = 0;
	while (is_whitespace(line[i]) == true)
		i++;
	if (ft_strncmp(line + i, "C", 1) != 0)
		return (PARSING_ERROR);
	splited_str = str_split_func(line + i + 1, &is_sep);
	if (splited_str == NULL)
		return (cub_perror("malloc error"), MALLOC_ERROR);
	if (arrstr_len(splited_str) != 3)
		return (free_splited_str(splited_str),
			cub_perror_file("unreconized line"), FATAL_PARSING_ERROR);
	if ((cub->parsed_flags & C_PARSED_FLAG) != 0)
		return (cub_perror_file("multiple definition of C color"),
			MULTIPLE_DEF_ERROR);
	ret_val = parse_rgb(&cub->c_col, splited_str);
	if (ret_val == 0)
		cub->parsed_flags |= C_PARSED_FLAG;
	return (ret_val);
}

static int	parse_rgb(t_uint32 *des, char **rgb)
{
	long	r;
	long	g;
	long	b;

	r = atoi_long(rgb[0]);
	g = atoi_long(rgb[1]);
	b = atoi_long(rgb[2]);
	free_splited_str(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (cub_perror_file("unreconized line"), FATAL_PARSING_ERROR);
	*des = ((r << 16) | (g << 8) | b);
	return (0);
}

static t_bool	is_sep(char c)
{
	return (is_whitespace(c) == true || c == ',' || c == '\n');
}
