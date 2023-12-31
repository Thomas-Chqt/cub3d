/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:25:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 12:10:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cubfile.h"
#include "error.h"

char	*gnl_no_empty(int fd)
{
	char	*line;

	(*cub_error_line())++;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_empty_str(line) == false)
			return (line);
		free(line);
		(*cub_error_line())++;
		line = get_next_line(fd);
	}
	return (line);
}
