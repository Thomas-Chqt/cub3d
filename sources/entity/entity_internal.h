/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:22:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 13:16:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_INTERNAL_H
# define ENTITY_INTERNAL_H

# include "entity.h"
# include "cubfile.h"
# include "error.h"

struct s_ent
{
	t_vec2f	pos;
	t_vec2f	dir;
	t_vec2f	pla;
};

t_ent	*new_ent_from_cfent(t_cfent *ent);

#endif // ENTITY_INTERNAL_H