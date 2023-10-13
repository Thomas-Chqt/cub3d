/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 22:03:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

int	load_cubfile(char *file)
{
	int	fd;

	ft_strlcpy(cub_error()->cubf, file, ERROR_FILES_MAX_LEN);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (set_error(CUBF_OPEN_ERROR), -1);
	cub_error()->line = 0;
	if (load_data(fd) != 0)
		return (-1);
	if (load_map(fd) != 0)
		return (-1);
	close(fd);
	if (check_map() != 0)
		return (-1);
	return (0);
}
