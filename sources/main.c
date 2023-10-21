/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/21 21:33:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

#ifdef DEBUG

__attribute__((destructor))
static void	destructor(void)
{
	print_report();
	system("leaks -q cub3d_debug");
}

#endif // DEBUG

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;

	argc = 2;
	argv[1] = "resources/maps/test.cub";
	cub3d = (t_cub3d){};
	if (argc != 2)
		return (set_error(BAD_ARGS_ERROR), cub_perror(), 1);
	if (create_window("cub3d", WIDTH, HEIGHT) != 0)
		return (set_error(MALLOC_ERROR), cub_perror(), 1);
	set_destructor((t_a)clean, &cub3d);
	if (setup(&cub3d, argv) != 0)
		return (delete_window(), cub_perror(), 2);
	start_main_loop((t_a)loop, &cub3d);
	return (0);
}
