/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 21:04:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 16:08:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubfile_internal.h"

static int	load_texture(t_cubf_data *data, char *line);
static int	load_color(t_cubf_data *data, char *line);

int	load_data(t_cubf_data *data, int fd)
{
	int		ret;
	char	*line;

	data->f_color = TRANSP;
	data->c_color = TRANSP;
	while (is_all_loaded(data) == false)
	{
		line = gnl_no_empty(fd);
		if (line == NULL)
			return (clean_data(data), set_error(UNEXP_EOF_ERROR), -1);
		ret = load_texture(data, line);
		if (ret == PARSING_ERROR)
			ret = load_color(data, line);
		if (ret == PARSING_ERROR)
			set_error(PARSING_ERROR);
		free(line);
		if (ret != 0)
			return (clean_data(data), -1);
	}
	set_error_texf("resources/textures/door.png");
	data->do_tex = ctx_from_img("resources/textures/door.png");
	if (data->do_tex == NULL)
		return (clean_data(data), set_error(ANIM_LOAD_ERROR), -1);
	return (0);
}

void	clean_data(t_cubf_data *data)
{
	free_context(data->no_tex);
	data->no_tex = NULL;
	free_context(data->so_tex);
	data->so_tex = NULL;
	free_context(data->we_tex);
	data->we_tex = NULL;
	free_context(data->ea_tex);
	data->ea_tex = NULL;
	free_context(data->do_tex);
	data->do_tex = NULL;
}

static int	load_texture(t_cubf_data *data, char *line)
{
	t_ctx	**dest;

	if (ft_strncmp(line, "NO", 2) == 0)
		dest = &(data->no_tex);
	else if (ft_strncmp(line, "SO", 2) == 0)
		dest = &(data->so_tex);
	else if (ft_strncmp(line, "WE", 2) == 0)
		dest = &(data->we_tex);
	else if (ft_strncmp(line, "EA", 2) == 0)
		dest = &(data->ea_tex);
	else
		return (PARSING_ERROR);
	if (is_whitespace(line[2]) == false)
		return (set_error(PARSING_ERROR), -1);
	if (*dest != NULL)
		return (set_error(MULTI_TEX_ERROR), -1);
	set_error_texf(normed(line + 3));
	*dest = ctx_from_img(normed(line + 3));
	if (*dest == NULL)
		return (set_error(TEXF_LOAD_ERROR), -1);
	return (0);
}

static int	load_color(t_cubf_data *data, char *line)
{
	t_uint32	*dest;
	char		**parsed_comp;

	if (ft_strncmp(line, "C", 1) == 0)
		dest = &(data->c_color);
	else if (ft_strncmp(line, "F", 1) == 0)
		dest = &(data->f_color);
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
