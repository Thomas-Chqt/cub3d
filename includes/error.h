/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:31:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/10 19:07:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "cub3d.h"

# define MALLOC_ERROR
# define BAD_ARGS_ERROR
# define NO_PLAYER_ERROR

# define PARSING_ERROR		
# define MULTI_TEXT_ERROR	
# define MULTI_COL_ERROR	
# define UNEP_EOF_ERROR		
# define WRONG_CHAR_ERROR	
# define BIG_MAP_ERROR		
# define LONG_LINE_ERROR	

# define TEX_LOAD_ERROR
	
# define NOT_CLOSED_ERROR	
# define DOUBLE_P_ERROR		

typedef struct t_cub3d_error
{
	char	*cubf;
	char	*texf;
	int		y;
	int		x;
	int		code;

}	t_cuberr;

t_cuberr	*cub_error(void);
void		cub_perror(char *str);

#endif // ERROR_H