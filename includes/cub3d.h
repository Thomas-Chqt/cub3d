/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/15 17:30:32 by tchoquet         ###   ########.fr       */
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

typedef enum e_map_tile { empty = -1, wall = 1 }				t_mtile;
typedef enum e_hit_side { no = -2, so = -1, ea = 1, we = 2 }	t_side;

typedef struct s_dda_res
{
	t_vec2f	dir;
	float	dist;
	t_side	hit_side;
	float	wall_x;

}	t_dres;

typedef struct s_cub3d
{
	t_ctx		*no_tex;
	t_ctx		*so_tex;
	t_ctx		*we_tex;
	t_ctx		*ea_tex;

	t_uint32	c_color;
	t_uint32	f_color;

	t_mtile		**map;
	t_vec2i		m_size;

	t_vec2f		p_pos;
	t_vec2f		p_dir;
	t_vec2f		p_plane;

	t_ctx		*mmap_ctx;
	t_ctx		*mmap_p_ctx;
	t_ctx		*rays_ctx;

	t_dres		dda_res[WIDTH];
	t_list		*sprite_lst;

}	t_cub3d;

t_cub3d	*cub3d(void);
int		setup(int argc, char *argv[]);
void	loop(void *none);
void	clean(void *none);

int		load_cubfile(char *file);
int		init_minimap(t_vec2i size);

void	pmove_fb(float dist);
void	pmove_lr(float dist);
void	protate(float rad);

void	run_dda(void);
void	sort_sprites(void);

void	render_walls(void);
void	render_sprites(void);
void	render_minimap(t_vec2i pos);

#endif // CUB3D_H
