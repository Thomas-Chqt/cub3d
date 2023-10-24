/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:04:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 13:38:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "cub3d.h"

void	render_walls(t_ent *pl, t_cubf *cubf, float *dist_ret);
t_ent	*entity_ray(t_ent *src, t_vec2f dir, t_list *ent_list, t_cubf *cub);

#endif // DDA_H