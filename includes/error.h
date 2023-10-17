/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:31:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 16:50:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "cub3d.h"

# define ERROR_FILES_MAX_LEN	100

# define BAD_ARGS_ERROR		0x1
# define MALLOC_ERROR		0x2
# define CUBF_OPEN_ERROR	0x3
# define UNEXP_EOF_ERROR	0x4
# define PARSING_ERROR		0x5
# define MULTI_TEX_ERROR	0x6
# define TEXF_LOAD_ERROR	0x7
# define MULTI_COL_ERROR	0x8
# define LONG_LINE_ERROR	0x9
# define BIG_MAP_ERROR		0xA
# define DOUBLE_P_ERROR		0xB
# define BAD_CHAR_ERROR		0xC
# define NO_P_ERROR			0xD
# define NOT_CLOSE_ERROR	0xE
# define ANIM_LOAD_ERROR	0xF

typedef struct t_cub3d_error
{
	char		cubf[ERROR_FILES_MAX_LEN];
	char		texf[ERROR_FILES_MAX_LEN];
	t_uint32	line;
	t_uint32	column;
	int			code;

}	t_cuberr;

t_cuberr	*cub_error(void);
void		set_error(t_uint32 code);
void		cub_perror(void);

#endif // ERROR_H