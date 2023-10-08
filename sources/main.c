/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/08 17:59:39 by tchoquet         ###   ########.fr       */
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

t_cub3d	*cub3d(void)
{
	static t_cub3d	global_data = {};

	return (&global_data);
}

int	main(int argc, char *argv[])
{
	// if (argc != 2)
	// 	return (cub_perror_set(BAD_ARGS_ERROR), 1);
	if(create_window("cub3d", (t_vec2i){WIDTH, HEIGHT}) != 0)
		return (cub_perror_set(MALLOC_ERROR), 2);
	if (setup("test.cub") != 0)
	{
		cub_perror(argv[1]);
		delete_window(3);
	}
	start_main_loop(&loop, NULL);
	return (0);
}

int	setup(char *cubf_path)
{
	set_destructor(&clean, NULL);
	set_back_color(0x00A0A0A0);
	if (load_cubfile(cubf_path, &cub3d()->cubf) != 0)
		return (-1);
	if (make_minimap((t_vec2i){WIDTH, HEIGHT}, (t_vec2i){0, 0}) != 0)
		return (-1);
	init_player();
	return (0);
}

void	loop(void *none)
{
	int	key;

	(void)none;
	while ((poll_key(&key)))
	{
		if (key == UP_KEY)
			pmov_f(0.1);
		if (key == DOWN_KEY)
			pmov_f(-0.1);
		if (key == LEFT_KEY)
			protate(-0.1);
		if (key == RIGHT_KEY)
			protate(0.1);
	}
	render_minimap();
}

void	clean(void *none)
{
	(void)none;
	free_cub_file(&cub3d()->cubf);
	free_minimap(&cub3d()->mmap);
}
