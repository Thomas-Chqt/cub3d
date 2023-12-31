/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:35:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/23 11:05:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define MMAP_SIZE 200
# define MMAP_POS_X 10
# define MMAP_POS_Y 10
# define MMAP_TSIZE 20
# define MMAP_PSIZE 5

int		make_mmap_overlay(t_ctx **dest);
void	render_mmap(t_cubf *cubf, t_ent *pl);

#endif // MINIMAP_H