/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/30 16:44:42 by tchoquet         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720

# define ERROR_MSG_MAX_LEN 100

# define MALLOC_ERROR 110

typedef enum e_map_tile
{
	badd = 0,
	wall = 1,
	none = 2,
	p_no = 3,
	p_so = 4,
	p_ea = 5,
	p_we = 6

} t_tile;

typedef struct s_map
{
	t_tile	**tiles;
	t_wh	size;
	
}	t_map;

typedef struct s_setup_data
{
	t_win		*window;
	t_2d_ctx	*window_ctx;
	t_map		map;
	
}	t_stpdata;

void	*cub_seterr(char *msg);
void	*cub_seterr_code(int code);
void	*cub_strerr(void);

t_map	load_map(char *file);

void	main_loop(t_stpdata *stpdata);
void	clean_stpdata(t_stpdata *stpdata);

#endif // CUB3D_H
