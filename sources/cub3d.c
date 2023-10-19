/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:44:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 16:38:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "cubfile.h"
#include "player.h"
#include "casting.h"
#include "render.h"
#include "inputs.h"
#include "sprite.h"
#include "hud.h"
#include "minimap.h"

int	setup(t_cub3d *cub, int argc, char *argv[])
{
	if (argc != 2)
		return (set_error(BAD_ARGS_ERROR), -1);
	if (create_window("cub3d", WIDTH, HEIGHT) != 0)
		return (set_error(MALLOC_ERROR), -1);
	set_destructor((t_vf) & clean, cub);
	if (setup_inputs(cub) != 0)
		return (delete_window(), -1);
	if (parse_cubfile(&cub->cubfile, argv[1]) != 0)
		return (delete_window(), -1);
	if (setup_player(&cub->player, cub->cubfile) != 0)
		return (clean(cub), -1);
	if (setup_casting(&cub->dda_result) != 0)
		return (clean(cub), -1);
	setup_sprites(cub->cubfile, &cub->sprite_list);
	if (setup_hud(&cub->hud) != 0)
		return (clean(cub), -1);
	if (setup_minimap(&cub->mmap) != 0)
		return (clean(cub), -1);
	return (0);
}

void	loop(t_cub3d *cub)
{
	update_timer(&cub->player->reload_timer);
	input_loop(cub);
	mouse_loop(cub);
	run_dda(cub->dda_result, cub->player, cub->cubfile);
	render_walls(cub->dda_result, cub->cubfile);
	lst_qcksort_data(cub->sprite_list, (t_sf)is_sp_closer, cub->player);
	lst_iterdata(cub->sprite_list, (t_vvf)render_sprite, cub);
	render_hud(cub->hud);
	render_minmap(cub->mmap, cub->cubfile, cub->player);
}

void	clean(t_cub3d *cub)
{
	clean_minimap(cub->mmap);
	clean_hud(cub->hud);
	ft_lstclear(&cub->sprite_list, (t_vf)free_sprite);
	free(cub->dda_result);
	free(cub->player);
	clean_cubfile(cub->cubfile);
	delete_window();
}
