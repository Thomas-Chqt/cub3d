/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:57:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 19:12:51 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_internal.h"

t_dda_data	make_dda_data(t_vec2f srt, t_vec2f dir, t_cubf *cubf)
{
	t_dda_data	ddata;

	ddata.srt = srt;
	ddata.dir = dir;
	ddata.tstep = (t_vec2i){1 + (-2 * (dir.x < 0)), 1 + (-2 * (dir.y < 0))};
	ddata.tcurr = vf2tovi2(srt);
	ddata.lstep = (t_vec2f){fabsf(1 / dir.x), fabsf(1 / dir.y)};
	if (dir.x < 0)
		ddata.lcurr.x = (srt.x - ddata.tcurr.x) * ddata.lstep.x;
	else
		ddata.lcurr.x = (ddata.tcurr.x + 1 - srt.x) * ddata.lstep.x;
	if (dir.y < 0)
		ddata.lcurr.y = (srt.y - ddata.tcurr.y) * ddata.lstep.y;
	else
		ddata.lcurr.y = (ddata.tcurr.y + 1 - srt.y) * ddata.lstep.y;
	ddata.h_tex = get_tex(cubf, no / (1 + (dir.y > 0)));
	ddata.v_tex = get_tex(cubf, we / (1 + (dir.x > 0)));
	return (ddata);
}
