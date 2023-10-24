/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:19:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 14:27:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "cub3d.h"

int		setup_entities(t_list **lst, t_cubf *cubf, t_ent **p_ref);
void	clean_entity(t_ent *ent);
void	entity_loop(t_ent *ent, t_cub3d *cub);
void	sort_entities(t_list *lst, t_ent *player);
void	render_entity(t_ent *ent, t_cub3d *cub);

void	render_hud(t_ent *player);

t_vec2f	ent_pos(t_ent *ent);
t_vec2f	ent_dir(t_ent *ent);
t_vec2f	ent_pla(t_ent *ent);
t_bool	is_alive(t_ent *ent);
t_bool	is_all_dead(t_list *ent_lst, t_ent *player);

void	mov_ent(t_cubf *cubf, t_ent *ent, t_vec2f vec);
void	rot_ent(t_ent *ent, float rad);

void	ent_shoot(t_ent *ent, t_list *ent_lst, t_cubf *cubf);
void	ent_take_dmg(t_ent *ent, int amount);

#endif // ENTITY_H