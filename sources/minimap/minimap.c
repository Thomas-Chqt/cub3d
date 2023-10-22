/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:35:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 15:52:40 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_internal.h"

void	draw_mmap_overlay(t_ctx *ctx)
{
	draw_rect(ctx,
		(t_vec2i){
		(ctx_size(ctx).x / 2) - ((ctx_size(ctx).x / 10) / 3) / 2,
		(ctx_size(ctx).y / 2) - ((ctx_size(ctx).y / 10) / 3) / 2},
		(t_vec2i){
		((ctx_size(ctx).x / 10) / 3),
		((ctx_size(ctx).x / 10) / 3)},
		RED);
}

void	draw_mmap(t_ctx *ctx, t_cubf *cubf, t_ent *pl)
{
	t_vec2i	curr;
	t_vec2f	curr_map;

	curr.y = 0;
	while (curr.y < ctx_size(ctx).y)
	{
		curr.x = 0;
		while (curr.x < ctx_size(ctx).x)
		{
			curr_map = add_vf2vf2(ent_pos(pl), (t_vec2f){
					((float)curr.x - (ctx_size(ctx).x / 2))
					/ (ctx_size(ctx).x / 10),
					((float)curr.y - (ctx_size(ctx).y / 2))
					/ (ctx_size(ctx).y / 10)});
			if (is_out_map(cubf, vf2tovi2(curr_map))
				|| is_solid(cubf, vf2tovi2(curr_map)))
				draw_pixel(ctx, curr, BLACK);
			else
				draw_pixel(ctx, curr, WHITE);
			curr.x++;
		}
		curr.y++;
	}
}
