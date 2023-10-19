/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:28:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 18:20:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define MMAP_POS_X		10
# define MMAP_POS_Y		10
# define MMAP_WIDTH		200
# define MMAP_HEIGHT	200
# define MMAP_TS	20
# define MMAP_PSIZE		6

struct s_mmap
{
	t_ctx	*ctx;
	t_ctx	*overlay_ctx;
};

int		setup_minimap(t_mmap **dest);
void	clean_minimap(t_mmap *mmap);

#endif // MINIMAP_H