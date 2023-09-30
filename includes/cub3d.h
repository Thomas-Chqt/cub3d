/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:34:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/30 15:01:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define USING_MLX

# include <libft.h>
# include <simpleWindow.h>
# include <DD_Graphics.h>

# ifdef DEBUG

#  include <libc.h>
#  include <memory_leak_detector.h>

# endif // DEBUG

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_setup_data
{
	t_win		*window;
	t_2d_ctx	*window_ctx;
	
}	t_stpdata;

void	main_loop(t_stpdata *stpdata);
void	clean_stpdata(t_stpdata *stpdata);

#endif // CUB3D_H
