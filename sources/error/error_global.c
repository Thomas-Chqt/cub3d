/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:05:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 12:05:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_internal.h"

t_cuberr	*cub_error(void)
{
	static t_cuberr	cub3d_error = {};

	return (&cub3d_error);
}
