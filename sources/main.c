/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 20:37:18 by tchoquet         ###   ########.fr       */
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
	t_stpdata	setup_data;

	argc = 2;
	argv[1] = "test.cub";
	if (argc != 2)
		return (ft_putendl_fd("Error\nbad arguments", STDERR_FILENO), 1);
	setup_data.window = new_window("cub3d", (t_wh){WIDTH, HEIGHT});
	if (setup_data.window == NULL)
		return (cub_perror_set(MALLOC_ERROR), 1);
	if (add_event(setup_data.window, ESC_KEY, ON_KEYDOWN, (t_func){
			(void (*)(void *)) & delete_window, setup_data.window}))
		return (cub_perror_set(MALLOC_ERROR),
			delete_window(setup_data.window), 1);
	setup(&setup_data, argv);
	start_main_loop((t_func){(void (*)(void *)) & loop, &setup_data});
	return (0);
}

void	setup(t_stpdata *stpdata, char *argv[])
{
	set_backcolor(stpdata->window, 0x00A0A0A0);
	set_destructor(stpdata->window, (t_func){clean, stpdata});
	if (load_cubfile(argv[1], &stpdata->cubf) != 0)
		return (cub_perror(argv[1]), delete_window(stpdata->window));
	if (make_minimap(&stpdata->mmap, &stpdata->cubf,
			(t_wh){WIDTH / 1, HEIGHT / 1},
		(t_pos){10, 10}) != 0)
		return (cub_perror(argv[1]), delete_window(stpdata->window));
	init_player(stpdata);
}

void	loop(t_stpdata *stpdata)
{
	int	key;

	while (poll_key(stpdata->window, &key))
	{
		if (key == UP_KEY)
			pmov_y(stpdata, -0.1);
		if (key == DOWN_KEY)
			pmov_y(stpdata, 0.1);
		if (key == LEFT_KEY)
			pmov_x(stpdata, -0.1);
		if (key == RIGHT_KEY)
			pmov_x(stpdata, 0.1);
	}
	render_minimap(stpdata);
}

void	clean(void *stpdata)
{
	free_cub_file(&((t_stpdata *)stpdata)->cubf);
	free_minimap(&((t_stpdata *)stpdata)->mmap);
}
