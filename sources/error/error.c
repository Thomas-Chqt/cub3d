/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 12:07:38 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_internal.h"

void	set_error(t_uint32 code)
{
	cub_error()->code = code;
}

void	set_error_cubf(char *file)
{
	ft_strlcpy(cub_error()->cubf, file, ERROR_FILES_MAX_LEN);
}

void	set_error_texf(char *file)
{
	ft_strlcpy(cub_error()->texf, file, ERROR_FILES_MAX_LEN);
}

t_uint32	*cub_error_line(void)
{
	return (&cub_error()->line);
}

t_uint32	*cub_error_column(void)
{
	return (&cub_error()->column);
}
