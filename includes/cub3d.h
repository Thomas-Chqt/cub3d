/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 14:46:18 by tchoquet         ###   ########.fr       */
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

# define PLAYER_AKT_SPEED 1
# define ENEMY_REATION_TIME 0.5

# define PLAYER_DMG	100
# define ENEMY_DMG	30

typedef void			(*t_a)(void *);
typedef void			(*t_b)(void *, void *);
typedef t_bool			(*t_c)(void *, void *, void *);

typedef struct s_cubf	t_cubf;
typedef struct s_ent	t_ent;

typedef struct s_cub3d
{
	t_cubf	*cubf;
	t_list	*ent_lst;
	t_ent	*p_ref;

	t_bool	is_m_block;
	t_vec2i	prev_mpos;

	t_ctx	*mmap_back;
	t_ctx	*mmap_overlay;
	t_ctx	*wall_ctx;

	float	wall_dist[WIDTH];

}	t_cub3d;

int		setup(t_cub3d *cub, char *file);
void	loop(t_cub3d *cub);
void	clean(t_cub3d *cub);

#endif // CUB3D_H
