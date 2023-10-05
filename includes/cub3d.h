/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/05 21:05:37 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define USING_MLX

# include <libc.h>

# include <libft.h>
# include <simpleWindow.h>

# ifdef DEBUG
#  include <memory_leak_detector.h>
# endif // DEBUG

# define WIDTH	1280
# define HEIGHT	720

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

typedef struct s_setup_data
{
	t_cubf	cub;
	t_win	*window;

}	t_stpdata;

void	main_loop(t_stpdata *stpdata);
void	clean_stpdata(t_stpdata *stpdata);

int		load_cubfile(char *file, t_cubf *cubf);
void	free_cub_file(t_cubf *cubf);

int		make_minimap(t_stpdata *stpdata);

#endif // CUB3D_H
