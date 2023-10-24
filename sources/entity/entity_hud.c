/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:45:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 14:23:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_internal.h"

void	render_hud(t_ent *player)
{
	float	img_x;
	int		x;

	img_x = 0;
	x = WIDTH / 2 - HUD_SIZE_X / 2;
	while (x < WIDTH / 2 + HUD_SIZE_X / 2)
	{
		draw_vstripe(
			back_ctx(),
			ctx_vstripe(player->img, (int)img_x),
			(t_vec2i){x, HEIGHT - HUD_SIZE_Y},
			(t_vec2i){x, HEIGHT});
		x++;
		img_x += (float)ctx_size(player->img).x / HUD_SIZE_X;
	}
	draw_rect(back_ctx(), (t_vec2i){20, HEIGHT - 40},
		(t_vec2i){304, 20}, WHITE);
	draw_rect(back_ctx(), (t_vec2i){22, HEIGHT - 38},
		(t_vec2i){player->hp * 3, 16}, RED);
}
