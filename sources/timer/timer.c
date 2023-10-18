/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:46:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 19:41:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "timer.h"

t_timer	new_timer(float s)
{
	return ((t_timer){
		.n = 0,
		.target = s * TIMER_FPS
	});
}

t_bool	update_timer(t_timer *timer)
{
	if (++(timer->n) >= timer->target)
		return (timer->n = timer->target, true);
	return (false);
}

void	reset_timer(t_timer *timer)
{
	timer->n = 0;
}
