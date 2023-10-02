/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/02 21:30:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_file_errdesc	*cub_file_err(void)
{
	static t_file_errdesc	file_error = {};

	return (&file_error);
}

void	cub_perror(char *msg)
{
	ft_putstr_fd("Error\ncub3d: ", STDERR_FILENO);
	perror(msg);
}

void	cub_perror_file(char *msg)
{
	ft_putstr_fd("Error\ncub3d: ", STDERR_FILENO);
	ft_putstr_fd(cub_file_err()->file, STDERR_FILENO);
	ft_putstr_fd(": line ", STDERR_FILENO);
	ft_putnbr_fd(cub_file_err()->line, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}
