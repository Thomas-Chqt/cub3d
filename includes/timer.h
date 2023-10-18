/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:43:08 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 18:50:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_H
# define TIMER_H

# define TIMER_FPS 60

# include "cub3d.h"

typedef struct s_timer
{
	int	n;
	int	target;

}	t_timer;

t_timer	new_timer(float s);
t_bool	update_timer(t_timer *timer);
void	reset_timer(t_timer *timer);

#endif // TIMER_H