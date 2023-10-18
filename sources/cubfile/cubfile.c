/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 15:23:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

int	parse_cubfile(t_cubf **dest, char *file)
{
	t_cubf	*cubf;
	int		fd;

	ft_strlcpy(cub_error()->cubf, file, ERROR_FILES_MAX_LEN);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (set_error(CUBF_OPEN_ERROR), -1);
	cubf = ft_calloc(1, sizeof(t_cubf));
	if (cubf == NULL)
		return (set_error(MALLOC_ERROR), -1);
	cubf->f_color = TRANSP;
	cubf->c_color = TRANSP;
	cub_error()->line = 0;
	if (load_data(cubf, fd) != 0)
		return (free(cubf), -1);
	if (load_map(cubf, fd) != 0)
		return (free_cubf_textures(cubf), free(cubf), -1);
	close(fd);
	if (check_map(cubf) != 0)
		return (clean_cubfile(cubf), -1);
	*dest = cubf;
	return (0);
}

void	clean_cubfile(t_cubf *cubf)
{
	int	i;

	free_cubf_textures(cubf);
	i = 0;
	while (cubf->map != NULL && i < cubf->m_size.y)
		free(cubf->map[i++]);
	free(cubf->map);
	free(cubf);
}
