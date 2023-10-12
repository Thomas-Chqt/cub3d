/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:04:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/12 17:33:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

static int	load_line(char *line);
static int	load_texture(char *line, t_ctx **dest);
static int	load_color(char *line, t_uint32 *dest);

int	load_data(int fd)
{
	char	*line;

	while (is_all_data_loaded() == false)
	{
		line = gnl_no_empty(fd);
		if (line == NULL)
			return (set_error((0b1100 << 28) | UNEXP_EOF), -1);
		if (load_line(normalized_line(line)) != 0)
			return (free(line), -1);
		free(line);
	}
	return (0);
}

static int	load_line(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "NO\t", 3) == 0)
		return (load_texture(line + 3, &cub3d()->no_tex));
	if (ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "SO\t", 3) == 0)
		return (load_texture(line + 3, &cub3d()->so_tex));
	if (ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "WE\t", 3) == 0)
		return (load_texture(line + 3, &cub3d()->we_tex));
	if (ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "EA\t", 3) == 0)
		return (load_texture(line + 3, &cub3d()->ea_tex));
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "F\t", 2) == 0)
		return (load_color(line + 2, &cub3d()->f_color));
	if (ft_strncmp(line, "C ", 2) == 0 || ft_strncmp(line, "C\t", 2) == 0)
		return (load_color(line + 2, &cub3d()->c_color));
	return (set_error((0b1100 << 28) | PARSING), -1);
}

static int	load_texture(char *line, t_ctx	**dest)
{
	if (is_empty_str(line))
		return (set_error((0b1100 << 28) | PARSING), -1);
	if (*dest != NULL)
		return (set_error((0b1100 << 28) | MULTI_TEXT), -1);
	cuberr_set_texf(normalized_line(line));
	*dest = ctx_from_img(normalized_line(line));
	if (*dest == NULL)
		return (set_error((0b1101 << 28) | PERROR), -1);
	return (0);
}

static int	load_color(char *line, t_uint32 *dest)
{
	char	**splited_line;

	if (is_empty_str(line))
		return (set_error((0b1100 << 28) | PARSING), -1);
	if (*dest != TRANSP)
		return (set_error((0b1100 << 28) | MULTI_COL), -1);
	splited_line = split_color_comp(line);
	if (splited_line == NULL)
		return (-1);
	*dest = (ft_atoi(splited_line[0]) << 16) 
		| (ft_atoi(splited_line[1]) << 8)
		| ft_atoi(splited_line[2]);
	free_splited_str(splited_line);
	return (0);
}
