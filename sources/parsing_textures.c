/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:05:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/02 21:24:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_no_text(char *line, t_cubfile *cub)
{
	t_uint64	i;

	i = 0;
	while (is_whitespace(line[i]) == true)
		i++;
	if (ft_strncmp(line + i, "NO", 2) != 0)
		return (PARSING_ERROR);
	if ((cub->parsed_flags & NO_PARSED_FLAG) != 0)
		return (cub_perror_file("multiple definition of NO texture"),
			MULTIPLE_DEF_ERROR);
	cub->no_tex = ft_strtrim(line + i + 2, "\t\n\v\f\r ");
	if (cub->no_tex == NULL)
		return (cub_perror("malloc error"), MALLOC_ERROR);
	cub->parsed_flags |= NO_PARSED_FLAG;
	return (0);
}

int	parse_so_text(char *line, t_cubfile *cub)
{
	t_uint64	i;

	i = 0;
	while (is_whitespace(line[i]) == true)
		i++;
	if (ft_strncmp(line + i, "SO", 2) != 0)
		return (PARSING_ERROR);
	if ((cub->parsed_flags & SO_PARSED_FLAG) != 0)
		return (cub_perror_file("multiple definition of SO texture"),
			MULTIPLE_DEF_ERROR);
	cub->so_tex = ft_strtrim(line + i + 2, "\t\n\v\f\r ");
	if (cub->so_tex == NULL)
		return (cub_perror("malloc error"), MALLOC_ERROR);
	cub->parsed_flags |= SO_PARSED_FLAG;
	return (0);
}

int	parse_we_text(char *line, t_cubfile *cub)
{
	t_uint64	i;

	i = 0;
	while (is_whitespace(line[i]) == true)
		i++;
	if (ft_strncmp(line + i, "WE", 2) != 0)
		return (PARSING_ERROR);
	if ((cub->parsed_flags & WE_PARSED_FLAG) != 0)
		return (cub_perror_file("multiple definition of WE texture"),
			MULTIPLE_DEF_ERROR);
	cub->we_tex = ft_strtrim(line + i + 2, "\t\n\v\f\r ");
	if (cub->we_tex == NULL)
		return (cub_perror("malloc error"), MALLOC_ERROR);
	cub->parsed_flags |= WE_PARSED_FLAG;
	return (0);
}

int	parse_ea_text(char *line, t_cubfile *cub)
{
	t_uint64	i;

	i = 0;
	while (is_whitespace(line[i]) == true)
		i++;
	if (ft_strncmp(line + i, "EA", 2) != 0)
		return (PARSING_ERROR);
	if ((cub->parsed_flags & EA_PARSED_FLAG) != 0)
		return (cub_perror_file("multiple definition of EA texture"),
			MULTIPLE_DEF_ERROR);
	cub->ea_tex = ft_strtrim(line + i + 2, "\t\n\v\f\r ");
	if (cub->ea_tex == NULL)
		return (cub_perror("malloc error"), MALLOC_ERROR);
	cub->parsed_flags |= EA_PARSED_FLAG;
	return (0);
}
