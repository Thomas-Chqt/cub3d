/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:35:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/23 13:28:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_internal.h"

int	make_mmap_overlay(t_ctx **dest)
{
	*dest = new_context((t_vec2i){MMAP_SIZE, MMAP_SIZE});
	if (*dest == NULL)
		return (set_error(MALLOC_ERROR), -1);
	draw_rect(*dest, (t_vec2i){
		(MMAP_SIZE / 2) - MMAP_PSIZE / 2,
		(MMAP_SIZE / 2) - MMAP_PSIZE / 2
	}, (t_vec2i){
		MMAP_PSIZE, MMAP_PSIZE
	}, RED);
	return (0);
}

void	render_mmap(t_cubf *cubf, t_ent *pl)
{
	t_vec2i	curr;
	t_vec2f	curr_map;

	curr.y = 0;
	while (curr.y < MMAP_SIZE)
	{
		curr.x = 0;
		while (curr.x < MMAP_SIZE)
		{
			curr_map = add_vf2vf2(ent_pos(pl), (t_vec2f){
					((float)curr.x - (MMAP_SIZE / 2)) / MMAP_TSIZE,
					((float)curr.y - (MMAP_SIZE / 2)) / MMAP_TSIZE});
			if (is_walkable(cubf, vf2tovi2(curr_map)))
				draw_pixel(back_ctx(), (t_vec2i){
					curr.x + MMAP_POS_X, curr.y + MMAP_POS_Y}, WHITE);
			else
				draw_pixel(back_ctx(), (t_vec2i){
					curr.x + MMAP_POS_X, curr.y + MMAP_POS_Y}, BLACK);
			curr.x++;
		}
		curr.y++;
	}
}
