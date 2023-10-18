/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:12:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 16:52:55 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"
#include "error.h"
#include "cubfile.h"

int	setup_player(t_play **dest, t_cubf *cubf)
{
	t_play	*play;

	play = ft_calloc(1, sizeof(t_play));
	if (play == NULL)
		return (set_error(MALLOC_ERROR), -1);
	play->pos = add_vf2vf2(vi2tovf2(cubf->p_srt_pos), (t_vec2f){0.5, 0.5});
	play->dir = char_to_dir_vec(cubf->p_srt_dir);
	play->plane = char_to_plane_vec(cubf->p_srt_dir);
	play->hitb = (t_vec2f){HIT_BOX_SIZE, HIT_BOX_SIZE};
	*dest = play;
	return (0);
}

void	pmove_fb(t_play *p, float dist, t_cubf *cubf)
{
	t_vec2f	mov_vec;

	mov_vec = mul_vf2f(p->dir, dist);
	if (!is_in_wall(p, (t_vec2f){p->pos.x + mov_vec.x, p->pos.y}, cubf))
		p->pos = (t_vec2f){p->pos.x + mov_vec.x, p->pos.y};
	if (!is_in_wall(p, (t_vec2f){p->pos.x, p->pos.y + mov_vec.y}, cubf))
		p->pos = (t_vec2f){p->pos.x, p->pos.y + mov_vec.y};
}

void	pmove_lr(t_play *p, float dist, t_cubf *cubf)
{
	t_vec2f	mov_vec;

	mov_vec = mul_vf2f(p->plane, dist);
	if (!is_in_wall(p, (t_vec2f){p->pos.x + mov_vec.x, p->pos.y}, cubf))
		p->pos = (t_vec2f){p->pos.x + mov_vec.x, p->pos.y};
	if (!is_in_wall(p, (t_vec2f){p->pos.x, p->pos.y + mov_vec.y}, cubf))
		p->pos = (t_vec2f){p->pos.x, p->pos.y + mov_vec.y};
}

void	protate(t_play *player, float rad)
{
	player->dir = rot_vf2(player->dir, rad);
	player->plane = rot_vf2(player->plane, rad);
}

void	clean_player(t_play *player)
{
	free(player);
}
