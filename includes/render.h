/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:40:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 13:49:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "casting.h"
# include "sprite.h"

typedef struct s_wall_data
{
	int			wall_srt;
	int			wall_end;
	t_stripe	stripe;

}	t_wall;

void	render_walls(t_dda *dda_res, t_cubf *cubf);
void	render_sprite(t_sprite *sp, t_cub3d *cub);
void	render_hud(t_hud *hud);

t_wall	init_wall_data(t_rres ray_res, t_cubf *cubf);
t_vec2i	transform_sppos(t_sprite *sp, float *dist, t_play *player);

#endif // RENDER_H