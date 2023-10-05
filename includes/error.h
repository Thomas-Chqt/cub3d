/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:31:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/04 18:09:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <errno.h>

# include "cub3d.h"

# define MALLOC_ERROR		110

# define PARSING_ERROR		150
# define MULTI_TEXT_ERROR	151
# define MULTI_COL_ERROR	156
# define UNEP_EOF_ERROR		157

# define WRONG_CHAR_ERROR	200
# define NOT_CLOSED_ERROR	201

typedef struct s_cub3d_file_error
{
	char	*file;
	int		line;
	int		code;

}	t_cub_ferr;

typedef struct s_cub3d_map_error
{
	int		row;
	int		collum;
	int		code;

}	t_cub_merr;

t_cub_ferr	*g_file_err(void);
t_cub_merr	*g_map_err(void);
int			*g_error(void);

void		set_error(int code);
void		cub_perror(char *str);

#endif // ERROR_H