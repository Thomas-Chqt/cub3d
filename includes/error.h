/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:31:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/12 13:27:50 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "cub3d.h"

# define ERROR_FILES_MAX_LEN	100

/*
? to create a error code, do: (0bBITS << 28) | DEFINE

? bit 1: Print the "cubf" string
? bit 2: Print a line number
? bit 3: Print a colum number (only if line is printed)
? bit 4: Print the "texf" string
*/

# define MALLOC		0x1
# define BAD_ARGS	0x2
# define PERROR		0x3
# define NO_PLAYER	0x4
# define PARSING	0x5
# define MULTI_TEXT	0x6
# define MULTI_COL	0x7
# define UNEXP_EOF	0x8
# define WRONG_CHAR	0x9
# define BIG_MAP	0xA
# define LONG_LINE	0xB
# define DOUBLE_P	0xC
# define NOT_CLOSE	0xD

typedef struct t_cub3d_error
{
	char		cubf[ERROR_FILES_MAX_LEN];
	char		texf[ERROR_FILES_MAX_LEN];
	int			y;
	int			x;
	t_uint32	code;

}	t_cuberr;

void		cuberr_set_cubf(char *s);
void		cuberr_set_texf(char *s);
void		set_error(t_uint32 code);

t_cuberr	*cub_error(void);
void		cub_perror(void);

#endif // ERROR_H