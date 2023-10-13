/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:04:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 21:38:14 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

static int	load_texture(char *line);
static int	load_color(char *line);

int	load_data(int fd)
{
	int		ret;
	char	*line;

	while (is_all_data_loaded() == false)
	{
		line = gnl_no_empty(fd);
		if (line == NULL)
			return (set_error(UNEXP_EOF_ERROR), -1);
		ret = load_texture(line);
		if (ret == PARSING_ERROR)
			ret = load_color(line);
		if (ret == PARSING_ERROR)
			set_error(PARSING_ERROR);
		free(line);
		if (ret != 0)
			return (-1);
	}
	return (0);
}

static int	load_texture(char *line)
{
	t_ctx	**dest;

	if (ft_strncmp(line, "NO", 2) == 0)
		dest = &(cub3d()->no_tex);
	else if (ft_strncmp(line, "SO", 2) == 0)
		dest = &(cub3d()->so_tex);
	else if (ft_strncmp(line, "WE", 2) == 0)
		dest = &(cub3d()->we_tex);
	else if (ft_strncmp(line, "EA", 2) == 0)
		dest = &(cub3d()->ea_tex);
	else
		return (PARSING_ERROR);
	if (is_whitespace(line[2]) == false)
		return (set_error(PARSING_ERROR), -1);
	if (*dest != NULL)
		return (set_error(MULTI_TEX_ERROR), -1);
	ft_strlcpy(cub_error()->texf, normed(line + 3), ERROR_FILES_MAX_LEN);
	*dest = ctx_from_img(normed(line + 3));
	if (*dest == NULL)
		return (set_error(TEXF_LOAD_ERROR), -1);
	return (0);
}

static int	load_color(char *line)
{
	t_uint32	*dest;
	char		**parsed_comp;

	if (ft_strncmp(line, "C", 1) == 0)
		dest = &(cub3d()->c_color);
	else if (ft_strncmp(line, "F", 1) == 0)
		dest = &(cub3d()->f_color);
	else
		return (PARSING_ERROR);
	if (is_whitespace(line[1]) == false)
		return (set_error(PARSING_ERROR), -1);
	if (*dest != TRANSP)
		return (set_error(MULTI_COL_ERROR), -1);
	parsed_comp = parse_color_comp(normed(line + 2));
	if (parsed_comp == NULL)
		return (-1);
	*dest = (ft_atoi(normed(parsed_comp[0])) << 16)
		| (ft_atoi(normed(parsed_comp[1])) << 8)
		| ft_atoi(normed(parsed_comp[2]));
	free_splited_str(parsed_comp);
	return (0);
}
