/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:35:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 21:33:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define MMAP_POS_X		10
# define MMAP_POS_Y		10
# define MMAP_WIDTH		200
# define MMAP_HEIGHT	200
# define MMAP_TS		20
# define MMAP_PSIZE		6

int		create_mmap_ctxs(t_cub3d *cub);
void	clean_mmap_ctxs(t_cub3d *cub);

#endif // MINIMAP_H