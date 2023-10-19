/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:41:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 18:20:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "cubfile.h"
#include "hud.h"
#include "player.h"
#include "minimap.h"

void	render_walls(t_dda *dda_res, t_cubf *cubf)
{
	int		x;
	t_wall	wall_data;

	x = 0;
	while (x < WIDTH)
	{
		wall_data = init_wall_data(dda_res->rres[x], cubf);
		if (wall_data.wall_srt > 0)
			draw_line(back_ctx(), (t_vec2i){x, 0},
				(t_vec2i){x, wall_data.wall_srt}, cubf->c_color);
		draw_vstripe(back_ctx(), wall_data.stripe,
			(t_vec2i){x, wall_data.wall_srt}, (t_vec2i){x, wall_data.wall_end});
		if (wall_data.wall_end < HEIGHT)
			draw_line(back_ctx(), (t_vec2i){x, wall_data.wall_end},
				(t_vec2i){x, HEIGHT}, cubf->f_color);
		x++;
	}
}

void	render_sprite(t_sprite *sp, t_cub3d *cub)
{
	float	sp_dist;
	t_vec2i	sp_screen_pos;
	t_vec2i	sp_size;
	int		x;
	float	tex_x;

	sp->img = request_anim_frame(&sp->curr_anim);
	sp_screen_pos = transform_sppos(sp, &sp_dist, cub->player);
	if (sp_dist <= 0)
		return ;
	sp_size = (t_vec2i){.x = ft_abs((int)(HEIGHT / (sp_dist))),
		.y = ft_abs((int)(HEIGHT / (sp_dist)))};
	x = (sp_screen_pos.x - (sp_size.x / 2)) - 1;
	tex_x = 0;
	while (++x < WIDTH && x < sp_screen_pos.x + (sp_size.x / 2))
	{
		if ((int)tex_x < ctx_size(sp->img).x
			&& x > 0 && sp_dist < cub->dda_result->rres[x].dist)
		{
			draw_vstripe(back_ctx(), ctx_vstripe(sp->img, (int)tex_x),
				(t_vec2i){x, sp_screen_pos.y - (sp_size.y / 2)},
				(t_vec2i){x, sp_screen_pos.y + (sp_size.y / 2)});
		}
		tex_x += (float)ctx_size(sp->img).x / (float)sp_size.x;
	}
}

void	render_hud(t_hud *hud)
{
	float	img_x;
	int		x;

	hud->img = request_anim_frame(&hud->curr_anim);
	img_x = 0;
	x = WIDTH / 2 - HUD_WIDTH / 2;
	while (x < WIDTH / 2 + HUD_WIDTH / 2)
	{
		draw_vstripe(
			back_ctx(),
			ctx_vstripe(hud->img, (int)img_x),
			(t_vec2i){x, HEIGHT - HUD_HEIGHT},
			(t_vec2i){x, HEIGHT});
		x++;
		img_x += (float)ctx_size(hud->img).x / HUD_WIDTH;
	}
}

void	render_minmap(t_mmap *mmap, t_cubf *cf, t_play *p)
{
	t_vec2i	curr;
	t_vec2i	curr_tile;

	curr.y = -MMAP_TS * (p->pos.y - (int)p->pos.y);
	curr_tile.y = (int)p->pos.y - ((MMAP_HEIGHT / 2) / MMAP_TS);
	while (curr.y < MMAP_HEIGHT)
	{
		curr.x = -MMAP_TS * (p->pos.x - (int)p->pos.x);
		curr_tile.x = (int)p->pos.x - ((MMAP_WIDTH / 2) / MMAP_TS);
		while (curr.x < MMAP_WIDTH)
		{
			if (curr_tile.y < 0 || curr_tile.x < 0
				|| curr_tile.y >= cf->m_size.y || curr_tile.x >= cf->m_size.x
				|| cf->map[curr_tile.y][curr_tile.x] >= wall)
				draw_rect(mmap->ctx, curr, (t_vec2i){MMAP_TS, MMAP_TS}, BLACK);
			else
				draw_rect(mmap->ctx, curr, (t_vec2i){MMAP_TS, MMAP_TS}, WHITE);
			curr.x += MMAP_TS;
			curr_tile.x++;
		}
		curr.y += MMAP_TS;
		curr_tile.y++;
	}
	put_context(mmap->ctx, (t_vec2i){MMAP_POS_X, MMAP_POS_Y});
	put_context(mmap->overlay_ctx, (t_vec2i){MMAP_POS_X, MMAP_POS_Y});
}
