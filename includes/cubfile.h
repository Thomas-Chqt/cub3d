/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:37:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 21:00:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBFILE_H
# define CUBFILE_H

# include "cub3d.h"

int		parse_cubfile(t_cubf **dest, char *file);

t_bool	is_out_map(t_cubf *cubf, t_vec2i pos);
t_bool	is_solid(t_cubf *cubf, t_vec2i pos);

void	clean_cubfile(t_cubf *cubf);

#endif // CUBFILE_H