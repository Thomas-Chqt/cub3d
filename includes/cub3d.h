/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 13:09:30 by tchoquet         ###   ########.fr       */
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

typedef void			(*t_a)(void *);

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

}	t_cub3d;

int		setup(t_cub3d *cub, char *file);
void	loop(t_cub3d *cub);
void	clean(t_cub3d *cub);

#endif // CUB3D_H
