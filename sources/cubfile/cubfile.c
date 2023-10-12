/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:39:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/11 23:12:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

int	load_cubfile(char *file)
{
	int	fd;

	cuberr_set_cubf(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (set_error((0b1000 << 28) | PERROR), -1);
	cub_error()->y = 0;
	if (load_data(fd) != 0)
		return (-1);
	return (0);
}
