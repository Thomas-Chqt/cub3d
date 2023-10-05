/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:44:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/04 23:36:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "error.h"

static int	parse_line(char *line, t_cubf *cubf);
static int	parse_texture(char *line, char **dest);
static int	parse_color(char *line, t_uint32 *dest);

int	parse_cubf_data(int fd, t_cubf *cubf)
{
	char	*line;

	cubf->f_col = NONE;
	cubf->c_col = NONE;
	while (is_data_all_parsed(cubf) == false)
	{
		g_file_err()->line++;
		line = get_next_line(fd);
		if (line == NULL)
			return (free_cub_file(cubf), set_error(UNEP_EOF_ERROR), -1);
		normalize_line(&line);
		if (parse_line(line, cubf) != 0)
			return (free_cub_file(cubf), free(line), -1);
		free(line);
	}
	return (0);
}

static int	parse_line(char *line, t_cubf *cubf)
{
	goto_line_start(&line);
	if (line[0] == '\0')
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (parse_texture(line + 3, &cubf->no_tex));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (parse_texture(line + 3, &cubf->so_tex));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (parse_texture(line + 3, &cubf->we_tex));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (parse_texture(line + 3, &cubf->ea_tex));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_color(line + 2, &cubf->f_col));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(line + 2, &cubf->c_col));
	return (set_error(PARSING_ERROR), -1);
}

static int	parse_texture(char *line, char **dest)
{
	goto_line_start(&line);
	if (line[0] == '\0')
		return (set_error(PARSING_ERROR), -1);
	if (*dest != NULL)
		return (set_error(MULTI_TEXT_ERROR), -1);
	*dest = ft_strtrim(line, "\t\n\v\f\r ");
	if (*dest == NULL)
		return (set_error(MALLOC_ERROR), -1);
	return (0);
}

static int	parse_color(char *line, t_uint32 *dest)
{
	char	**splited_str;
	long	r;
	long	g;
	long	b;

	goto_line_start(&line);
	if (line[0] == '\0')
		return (set_error(PARSING_ERROR), -1);
	splited_str = str_split_func(line, &is_color_comp_sep);
	if (splited_str == NULL)
		return (set_error(MALLOC_ERROR), -1);
	if (arrstr_len(splited_str) != 3)
		return (free_splited_str(splited_str), set_error(PARSING_ERROR), -1);
	if (*dest != NONE)
		return (free_splited_str(splited_str), set_error(MULTI_COL_ERROR), -1);
	r = atoi_long(splited_str[0]);
	g = atoi_long(splited_str[1]);
	b = atoi_long(splited_str[2]);
	free_splited_str(splited_str);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (set_error(PARSING_ERROR), -1);
	*dest = ((r << 16) | (g << 8) | b);
	return (0);
}
