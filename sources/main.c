/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/06 13:49:54 by tchoquet         ###   ########.fr       */
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

	if (argc != 2)
		return (ft_putendl_fd("Error\nbad arguments", STDERR_FILENO), 1);
	setup_data.window = new_window("cub3d", (t_wh){WIDTH, HEIGHT});
	if (setup_data.window == NULL)
		return (ft_putendl_fd("Error\nfail to open window", STDERR_FILENO), 1);
	setup(&setup_data, argv);
	start_main_loop((t_func){(void (*)(void *)) & loop, &setup_data});
	return (0);
}

void	setup(t_stpdata *stpdata, char *argv[])
{
	set_backcolor(stpdata->window, 0x00A0A0A0);
	set_destructor(stpdata->window, (t_func){clean, stpdata});
	stpdata->minimap_pos = (t_pos){10, 10};
	stpdata->minimap_size = (t_wh){WIDTH / 4, HEIGHT / 4};
	if (load_cubfile(argv[1], &stpdata->cub) != 0)
		return (cub_perror(argv[1]), delete_window(stpdata->window));
	if (make_minimap(stpdata, stpdata->minimap_size) != 0)
		return (cub_perror(argv[1]), delete_window(stpdata->window));
}

void	loop(t_stpdata *stpdata)
{
	put_ctx_to_win(stpdata->window, stpdata->minimap_ctx, (t_pos){10, 10});
}

void	clean(void *stpdata)
{
	free_cub_file(&((t_stpdata *)stpdata)->cub);
	delete_ctx(((t_stpdata *)stpdata)->minimap_ctx);
}
