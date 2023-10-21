/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:22:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 20:58:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_INTENAL_H
# define ENTITY_INTENAL_H

# include "entity.h"

struct s_ent
{
	t_vec2f	pos;
	t_vec2f	dir;
	t_vec2f	pla;
};

t_list	make_entity_lst(t_cubf *cubf, t_list **lst, t_ent **p_ref)

#endif // ENTITY_INTENAL_H