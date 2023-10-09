/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:45:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/09 19:53:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "cub3d.h"

t_vec2f	get_ray_dir(int x);
void	set_tile_step(t_dda *dest);
void	set_length_step(t_dda *dest);
void	set_start_length(t_dda *dest);

#endif // DDA_H