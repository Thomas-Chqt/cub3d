/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:12:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 13:35:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

void	on_cmd_down(void *none)
{
	show_mouse();
	cub3d()->is_m_block = false;
	desac_poll_key();
}

void	on_cmd_up(void *none)
{
	hide_mouse();
	cub3d()->is_m_block = true;
	react_poll_key();
}