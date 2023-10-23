/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:01:15 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/23 13:17:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# include "cub3d.h"

# define TIMER_FPS 60

typedef struct s_timer
{
	int	n;
	int	target;

}	t_timer;

t_timer	new_timer(float s);
void	update_timer(t_timer *timer);
float	timer_status(t_timer timer);

#endif // TIMER_H