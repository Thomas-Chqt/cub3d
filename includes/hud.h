/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:18:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/19 13:56:38 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "cub3d.h"
# include "animation.h"

# define HUD_WIDTH 600
# define HUD_HEIGHT 600

struct s_hud
{
	t_ctx	*img;

	t_anim	curr_anim;

	t_anim	idle_anim;
	t_anim	shoot_anim;
};

int		setup_hud(t_hud **dest);
void	clean_hud(t_hud *hud);

#endif // HUD_H