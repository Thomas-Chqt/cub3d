/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:05:43 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/10 18:25:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

t_cub_ferr	*g_file_err(void)
{
	static t_cub_ferr	global_file_error = {NULL, 0, 0};

	return (&global_file_error);
}

t_cub_merr	*g_map_err(void)
{
	static t_cub_merr	global_map_error = {0, 0, 0};

	return (&global_map_error);
}

int	*g_error(void)
{
	static int	global_error = 0;

	return (&global_error);
}
