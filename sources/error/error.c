/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/15 16:54:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void		put_premsg(void);

t_cuberr	*cub_error(void)
{
	static t_cuberr	cub3d_error = {};

	return (&cub3d_error);
}

void	set_error(t_uint32 code)
{
	cub_error()->code = code;
}
