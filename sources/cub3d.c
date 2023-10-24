/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:44:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 20:26:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "cubfile.h"
#include "inputs.h"
#include "minimap.h"
#include "entity.h"
#include "dda.h"

static void	clean_setup(t_cub3d *cub);

int	setup(t_cub3d *cub, char *file)
{
	if (parse_cubfile(&cub->cubf, file) != 0)
		return (clean_setup(cub), -1);
	if (setup_inputs(cub) != 0)
		return (clean_setup(cub), -1);
	if (make_mmap_overlay(&cub->mmap_overlay) != 0)
		return (clean_setup(cub), -1);
	if (setup_entities(&cub->ent_lst, cub->cubf, &cub->p_ref) != 0)
		return (clean_setup(cub), -1);
	return (0);
}

void	loop(t_cub3d *cub)
{
	handle_inputs(cub);
	lst_iterdata(cub->ent_lst, (t_b)entity_loop, cub);
	render_walls(cub->p_ref, cub->cubf, cub->wall_dist);
	sort_entities(cub->ent_lst, cub->p_ref);
	lst_iterdata(cub->ent_lst, (t_b)render_entity, cub);
	render_hud(cub->p_ref);
	render_mmap(cub->cubf, cub->p_ref);
	put_context(cub->mmap_overlay, (t_vec2i){MMAP_POS_X, MMAP_POS_Y});
}

void	clean(t_cub3d *cub)
{
	clean_setup(cub);
	delete_window();
}

static void	clean_setup(t_cub3d *cub)
{
	ft_lstclear(&cub->ent_lst, (t_a)clean_entity);
	free_context(cub->mmap_overlay);
	clean_cubfile(cub->cubf);
}
