/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:02:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/23 18:32:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

t_timer	new_timer(float s)
{
	return ((t_timer){
		.n = 0,
		.target = s * TIMER_FPS
	});
}

void	update_timer(t_timer *timer)
{
	if (timer->n < timer->target)
		timer->n++;
}

float	timer_status(t_timer timer)
{
	if (timer.target == 0)
		return (0);
	return (timer.n / timer.target);
}
