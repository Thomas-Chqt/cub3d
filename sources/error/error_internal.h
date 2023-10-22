/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:00:43 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 13:16:41 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_INTERNAL_H
# define ERROR_INTERNAL_H

# include "error.h"

# define ERROR_FILES_MAX_LEN	100

typedef struct t_cub3d_error
{
	char		cubf[ERROR_FILES_MAX_LEN];
	char		texf[ERROR_FILES_MAX_LEN];
	t_uint32	line;
	t_uint32	column;
	int			code;

}	t_cuberr;

t_cuberr	*cub_error(void);

#endif // ERROR_INTERNAL_H