/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:14:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/16 17:20:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include "Graphics_internal.h"

struct s_context
{
	void		*mlx_image;
	t_uint32	*pixels;
	t_uint32	**vstripes;
	t_vec2i		size;
};

t_uint32	*px(t_ctx *context, t_vec2i pos);
t_ctx		*ctx_from_mlx_img(void *mlx_img, t_vec2i size);
int			compute_vstripes(t_ctx *ctx);
void		fill_vstripes(t_ctx *ctx);

#endif // CONTEXT_H