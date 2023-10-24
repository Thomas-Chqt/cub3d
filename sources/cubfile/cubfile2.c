/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:34:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 16:10:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubfile_internal.h"

t_ctx	*get_tex(t_cubf *cubf, t_side side)
{
	if (side == no)
		return (cubf->data.no_tex);
	if (side == so)
		return (cubf->data.so_tex);
	if (side == we)
		return (cubf->data.we_tex);
	if (side == ea)
		return (cubf->data.ea_tex);
	return (NULL);
}

t_ctx	*get_do_tex(t_cubf *cubf)
{
	return (cubf->data.do_tex);
}

t_uint32	get_c_color(t_cubf *cubf)
{
	return (cubf->data.c_color);
}

t_uint32	get_f_color(t_cubf *cubf)
{
	return (cubf->data.f_color);
}
