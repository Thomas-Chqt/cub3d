/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:25:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 14:45:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

char	*gnl_no_empty(int fd)
{
	char	*line;

	cub_error()->line++;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_empty_str(line) == false)
			return (line);
		free(line);
		cub_error()->line++;
		line = get_next_line(fd);
	}
	return (line);
}

void	free_cubf_textures(t_cubf *cubf)
{
	free_context(cubf->no_tex);
	free_context(cubf->so_tex);
	free_context(cubf->we_tex);
	free_context(cubf->ea_tex);
}
