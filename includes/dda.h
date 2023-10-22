/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:04:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 17:53:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "cub3d.h"

void	draw_walls(t_ctx *ctx, t_ent *pl, t_cubf *cubf, float *dist_ret);

#endif // DDA_H