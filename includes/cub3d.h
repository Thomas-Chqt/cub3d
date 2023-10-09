/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/09 22:01:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <Graphics.h>

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
	t_vec2i		size;
	t_vec2i		p_start;
	t_tile		p_start_rot;

}	t_cubf;

typedef struct s_minimap
{
	t_ctx	*ctx;
	t_vec2i	pos;
	t_ctx	*p_ctx;

}	t_mmap;

typedef struct s_player
{
	t_vec2f	pos;
	t_vec2f	dir;
	t_vec2f	plane;

}	t_player;

typedef enum e_hit_side
{
	no,
	so,
	ea,
	we
}	t_side;

typedef struct s_dda
{
	t_vec2f	start;
	t_vec2f	dir;

	t_vec2i	tile_step;
	t_vec2i	curr_tile;

	t_vec2f	length_step;
	t_vec2f	curr_length;

	float	dist;
	t_side	hit_side;
	float	wall_x;

}	t_dda;

typedef struct s_cub3d
{
	t_cubf		cubf;
	t_mmap		mmap;
	t_player	player;

	t_dda		dda_res[WIDTH];
	t_ctx		*wall_ctx;

}	t_cub3d;

t_cub3d	*cub3d(void);
int		setup(char *cubf_path);
void	loop(void *none);
void	clean(void *none);

int		load_cubfile(char *file, t_cubf *cubf);
void	free_cub_file(t_cubf *cubf);

int		make_minimap(t_vec2i size, t_vec2i pos);
t_vec2i	tile_size_px(void);
void	free_minimap(t_mmap *mmap);

void	init_player(void);
void	set_ppos(t_vec2f pos);
void	pmov_x(float dist);
void	pmov_y(float dist);
void	pmov_f(float dist);
void	protate(float rad);

void	run_dda(void);

void	draw_walls(void);

void	render_minimap(void);

#endif // CUB3D_H
