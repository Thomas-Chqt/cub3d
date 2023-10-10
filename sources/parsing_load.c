/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:05:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/10 15:49:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "error.h"

int	load_textures(t_cubf *cubf)
{
	cubf->no_ctx = ctx_from_img(cubf->no_tex);
	cubf->so_ctx = ctx_from_img(cubf->so_tex);
	cubf->we_ctx = ctx_from_img(cubf->we_tex);
	cubf->ea_ctx = ctx_from_img(cubf->ea_tex);
	if (cubf->no_ctx == NULL
		|| cubf->so_ctx == NULL
		|| cubf->we_ctx == NULL
		|| cubf->ea_ctx == NULL)
	{
		free_context(cubf->no_ctx);
		cubf->no_ctx = NULL;
		free_context(cubf->so_ctx);
		cubf->so_ctx = NULL;
		free_context(cubf->we_ctx);
		cubf->we_ctx = NULL;
		free_context(cubf->ea_ctx);
		cubf->ea_ctx = NULL;
		set_error(TEX_LOAD_ERROR);
		return (-1);
	}
	return (0);
}
