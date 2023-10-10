/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/10 18:26:44 by tchoquet         ###   ########.fr       */
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
{argc = 2; argv[1] = "resources/maps/test.cub";
	if (argc != 2)
		return (cub_perror_set(BAD_ARGS_ERROR), 1);
	if (create_window("cub3d", (t_vec2i){WIDTH, HEIGHT}) != 0)
		return (cub_perror_set(MALLOC_ERROR), 2);
	set_destructor(&clean, NULL);
	start_main_loop(&loop, NULL);
	return (0);
}

int	setup(char *cubf_path)
{
	return (0);
}

void	loop(void *none)
{
	int	key;

	(void)none;
	while ((poll_key(&key)))
	{
		if (key == W_KEY)
			;
		if (key == S_KEY)
			;
		if (key == D_KEY)
			;
		if (key == A_KEY)
			;
		if (key == LEFT_KEY)
			;
		if (key == RIGHT_KEY)
			;
	}
}

void	clean(void *none)
{
	(void)none;
}
