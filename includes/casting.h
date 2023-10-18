/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:26:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 20:50:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

# include "cub3d.h"
# include "sprite.h"

typedef enum e_hit_side { no = -2, so = -1, ea = 1, we = 2 }	t_side;

typedef struct s_ray_res
{
	t_vec2f		dir;
	float		dist;
	t_side		hit_side;
	float		wall_x;
	t_sprite	*hit_sprite;

}	t_rres;

struct s_dda
{
	t_rres	rres[WIDTH];
};

typedef struct s_dda_data
{
	t_vec2f	start;
	t_vec2f	dir;

	t_vec2i	tile_step;
	t_vec2i	curr_tile;

	t_vec2f	length_step;
	t_vec2f	curr_length;

	t_side	v_side;
	t_side	h_side;

}	t_dda_data;

int			setup_casting(t_dda **dest);
void		run_dda(t_dda *res, t_play *player, t_cub3d *cub);
t_sprite	*dda_one_ray(t_vec2f start, t_vec2f dir, t_cub3d *cub);
void		clean_casting(t_dda *dda);

t_dda_data	make_dda_data(t_vec2f start, t_vec2f dir);
t_bool		sould_stop(t_rres *res, t_dda_data *data, t_cub3d *cub, t_bool sp);

#endif // CASTING_H