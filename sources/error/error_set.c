/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:39:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/11 20:43:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	cuberr_set_cubf(char *s)
{
	ft_strlcpy(cub_error()->cubf, s, ERROR_FILES_MAX_LEN);
}

void	cuberr_set_texf(char *s)
{
	ft_strlcpy(cub_error()->texf, s, ERROR_FILES_MAX_LEN);
}

void	set_error(t_uint32 code)
{
	cub_error()->code = code;
}
