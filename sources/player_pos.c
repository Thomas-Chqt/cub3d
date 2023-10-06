/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:28:10 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 19:28:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_in_wall(t_stpdata *stpdata, t_vect2d p_pos);

void	set_ppos(t_stpdata *stpdata, t_vect2d pos)
{
	if (is_in_wall(stpdata, pos))
		return ;
	stpdata->play.pos = pos;
}

void	pmov_x(t_stpdata *stpdata, float dist)
{
	set_ppos(stpdata, (t_vect2d){
		stpdata->play.pos.x + dist,
		stpdata->play.pos.y
	});
}

void	pmov_y(t_stpdata *stpdata, float dist)
{
	set_ppos(stpdata, (t_vect2d){
		stpdata->play.pos.x,
		stpdata->play.pos.y + dist
	});
}

static t_bool	is_in_wall(t_stpdata *stpdata, t_vect2d p_pos)
{
	float	p_size;
	t_vect2d	t_l;
	t_vect2d	t_r;
	t_vect2d	b_l;
	t_vect2d	b_r;

	p_size = stpdata->mmap.p_size;
	t_l = (t_vect2d){p_pos.x - (p_size / 2), p_pos.y - (p_size / 2)};
	t_r = (t_vect2d){p_pos.x + (p_size / 2), p_pos.y - (p_size / 2)};
	b_l = (t_vect2d){p_pos.x - (p_size / 2), p_pos.y + (p_size / 2)};
	b_r = (t_vect2d){p_pos.x + (p_size / 2), p_pos.y + (p_size / 2)};
	if (stpdata->cubf.tiles[(int)(t_l.y)][(int)t_l.x] < ins)
		return (true);
	if (stpdata->cubf.tiles[(int)t_r.y][(int)t_r.x] < ins)
		return (true);
	if (stpdata->cubf.tiles[(int)b_l.y][(int)b_l.x] < ins)
		return (true);
	if (stpdata->cubf.tiles[(int)b_r.y][(int)b_r.x] < ins)
		return (true);
	return (false);
}
