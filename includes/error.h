/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:31:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 12:04:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "cub3d.h"

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

void		set_error(t_uint32 code);
void		set_error_cubf(char *file);
void		set_error_texf(char *file);
t_uint32	*cub_error_line(void);
t_uint32	*cub_error_column(void);
void		cub_perror(void);

#endif // ERROR_H