/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:58:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 20:57:55 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include "cub3d.h"

int		setup_inputs(t_cub3d *cub);
void	input_loop(t_cub3d *cub);
void	mouse_loop(t_cub3d *cub);

void	on_cmd_down(t_cub3d *cub);
void	on_cmd_up(t_cub3d *cub);
void	on_l_click(t_cub3d *cub);

#endif // INPUTS_H