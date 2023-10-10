/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:55:30 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/10 18:56:08 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

t_cuberr	*cub_error(void)
{
	static t_cuberr	cub3d_error = {0};

	return (&cub3d_error);
}
