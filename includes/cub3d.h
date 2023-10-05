/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/04 18:36:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define USING_MLX

# include <libc.h>

# include <libft.h>
# include <simpleWindow.h>
# include <DD_Graphics.h>

# ifdef DEBUG
#  include <memory_leak_detector.h>
# endif // DEBUG

# define WIDTH	1280
# define HEIGHT	720

# ifndef WHI_TYPE
#  define WHI_TYPE

typedef struct s_width_height_int
{
	int	w;
	int	h;

}	t_whi;

# endif // WHI_TYPE

typedef enum e_map_tile
{
	out = 0,
	wal = 1,
	ins = 2,
	pno = 3,
	pso = 4,
	pea = 4,
	pwe = 6
}	t_tile;

typedef struct s_cub_file
{
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	t_uint32	f_col;
	t_uint32	c_col;

	t_tile		**tiles;
	t_whi		size;
	t_pos		p_start;

}	t_cubf;

typedef struct s_setup_data
{
	t_win		*window;
	t_2d_ctx	*window_ctx;
	t_cubf		cub;

}	t_stpdata;

void	main_loop(t_stpdata *stpdata);
void	clean_stpdata(t_stpdata *stpdata);

int		load_cubfile(char *file, t_cubf *cubf);
void	free_cub_file(t_cubf *cubf);

#endif // CUB3D_H
