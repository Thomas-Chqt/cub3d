/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/03 18:04:40 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define USING_MLX

# include <libc.h>
# include <errno.h>

# include <libft.h>
# include <simpleWindow.h>
# include <DD_Graphics.h>

# ifdef DEBUG
#  include <memory_leak_detector.h>
# endif // DEBUG

# define MALLOC_ERROR			110
# define PARSING_ERROR			111
# define MULTIPLE_DEF_ERROR		112
# define UNEXPECTED_EOF_ERROR	113
# define FATAL_PARSING_ERROR	114
# define WRONG_CHARACTER		115

# define WIDTH	1280
# define HEIGHT	720

typedef enum e_map_tile
{
	out =	0,
	wall =	1,
	empty =	2,
	p_no =	3,
	p_so =	4,
	p_ea =	4,
	p_we =	6
}	t_tile;

typedef struct s_cubfile
{
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	t_uint32	f_col;
	t_uint32	c_col;

	char		parsed_flags;

	t_tile		*tiles;
	int			width;
	int			height;

	t_pos		p_pos;
	t_tile		p_dir;

}	t_cubfile;

typedef struct s_setup_data
{
	t_win		*window;
	t_2d_ctx	*window_ctx;
	t_cubfile	cub;

}	t_stpdata;

typedef struct s_file_error_description
{
	char	*file;
	int		line;

}	t_file_errdesc;

void			main_loop(t_stpdata *stpdata);
void			clean_stpdata(t_stpdata *stpdata);

t_file_errdesc	*cub_file_err(void);
void			cub_perror(char *msg);
void			cub_perror_file(char *msg);

t_cubfile		load_cubfile(char *file);
void			free_cubfile(t_cubfile cub);
t_tile			*get_tile(t_cubfile cub, t_pos pos);

#endif // CUB3D_H
