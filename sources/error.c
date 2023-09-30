/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/30 16:32:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*cub_error_buff(void)
{
	static char	error_buffer[ERROR_MSG_MAX_LEN] = {};
	
	return (error_buffer);
}

void	*cub_seterr(char *msg)
{
	ft_strlcpy(cub_error_buff(), msg, ERROR_MSG_MAX_LEN);
	return (NULL);
}

void	*cub_seterr_code(int code)
{
	if (code == MALLOC_ERROR)
		return (cub_seterr("Malloc error"));
	return (cub_seterr(strerror(code)));
}

void	*cub_strerr(void)
{
	return (cub_error_buff());
}
