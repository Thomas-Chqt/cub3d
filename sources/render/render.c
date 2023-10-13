/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:41:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 16:04:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	render_minimap(t_vec2i pos)
{
	put_context(cub3d()->mmap_ctx, pos);
	put_context(cub3d()->mmap_p_ctx,
		sub_vi2vi2(mtos(cub3d()->p_pos, pos),
			div_vi2vi2(ctx_size(cub3d()->mmap_p_ctx), (t_vec2i){2, 2})));
}
