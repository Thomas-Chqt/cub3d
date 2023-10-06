/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 19:55:18 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <simpleWindow.h>

# include "external_functions.h"

# ifdef DEBUG
#  include <memory_leak_detector.h>
# endif // DEBUG

# define WIDTH	1280
# define HEIGHT	720
# define FOV	90

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
	t_wh		size;
	t_pos		p_start;
	t_tile		p_start_rot;

}	t_cubf;

typedef struct s_minimap
{
	t_ctx	*ctx;
	t_pos	pos;
	t_wh	ti_size;
	t_ctx	*p_ctx;
	float	p_size;
	t_ctx	*ray_ctx;

}	t_minimap;

typedef struct s_player
{
	t_vect2d	pos;
	t_vect2d	dir;
	t_vect2d	plane;

}	t_player;


typedef struct s_setup_data
{
	t_win	*window;

	t_cubf		cubf;
	t_minimap	mmap;
	t_player	play;

}	t_stpdata;

void		setup(t_stpdata *stpdata, char *argv[]);
void		loop(t_stpdata *stpdata);
void		clean(void *stpdata);

int			load_cubfile(char *file, t_cubf *cubf);
void		free_cub_file(t_cubf *cubf);

int			make_minimap(t_minimap *mmap, t_cubf *cubf, t_wh size, t_pos pos);
void		free_minimap(t_minimap	*mmap);

void		init_player(t_stpdata *stpdata);
void		set_ppos(t_stpdata *stpdata, t_vect2d pos);
void		pmov_x(t_stpdata *stpdata, float dist);
void		pmov_y(t_stpdata *stpdata, float dist);

void		render_minimap(t_stpdata *stpdata);

#endif // CUB3D_H
