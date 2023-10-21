/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:58:05 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 21:33:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include "cub3d.h"

int		setup_inputs(t_cub3d *cub);
void	handle_inputs(t_cub3d *cub);

#endif // INPUTS_H