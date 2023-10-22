/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:19:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 17:44:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "cub3d.h"

int		setup_entities(t_cub3d *cub);
t_vec2f	ent_pos(t_ent *ent);
t_vec2f	ent_dir(t_ent *ent);
t_vec2f	ent_pla(t_ent *ent);
void	mov_ent(t_cubf *cubf, t_ent *ent, t_vec2f vec);
void	rot_ent(t_ent *ent, float rad);
void	clean_entities(t_cub3d *cub);

#endif // ENTITY_H