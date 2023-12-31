/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:21:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/24 19:54:58 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_INTERNAL_H
# define INPUTS_INTERNAL_H

# include "inputs.h"
# include "error.h"
# include "entity.h"
# include "cubfile.h"

void	on_cmd_down(t_cub3d *cub);
void	on_cmd_up(t_cub3d *cub);
void	on_l_click(t_cub3d *cub);
void	on_f_down(t_cub3d *cub);

#endif // INPUTS_INTERNAL_H