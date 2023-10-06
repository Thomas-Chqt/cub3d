/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:56:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 20:40:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	render_minimap(t_stpdata *stpdata)
{
	put_ctx_to_win(stpdata->window, stpdata->mmap.ctx, stpdata->mmap.pos);
	put_ctx_to_win(stpdata->window, stpdata->mmap.p_ctx,
		to_screen_coord(
			addvect2df(stpdata->play.pos, -(stpdata->mmap.p_size / 2)),
			&stpdata->mmap));
	clear_ctx(stpdata->mmap.ray_ctx);
	put_line(stpdata->mmap.ray_ctx,
		to_screen_coord(stpdata->play.pos, &stpdata->mmap),
		to_screen_coord(
			(t_vect2d){0,0},
			&stpdata->mmap), RED);
	put_ctx_to_win(stpdata->window, stpdata->mmap.ray_ctx, stpdata->mmap.pos);
}
