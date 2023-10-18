/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 19:08:19 by tchoquet         ###   ########.fr       */
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

typedef void			(*t_vf)(void *);
typedef t_bool			(*t_sf)(void *, void *, void *);
typedef void			(*t_vvf)(void *, void *);

typedef struct s_cubf	t_cubf;
typedef struct s_play	t_play;
typedef struct s_dda	t_dda;
typedef struct s_anims	t_anims;

typedef struct s_cub3d
{
	t_cubf	*cubfile;
	t_play	*player;
	t_dda	*dda_result;
	t_list	*sprite_list;
	t_anims	*animations;

	t_vec2i	prev_mpos;
	t_bool	is_m_block;

}	t_cub3d;

int		setup(t_cub3d *cub, int argc, char *argv[]);
void	loop(t_cub3d *cub);
void	clean(t_cub3d *cub);

#endif // CUB3D_H
