/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:35:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 15:47:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

void	draw_mmap_overlay(t_ctx *ctx);
void	draw_mmap(t_ctx *ctx, t_cubf *cubf, t_ent *player);

#endif // MINIMAP_H