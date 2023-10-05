/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/05 21:02:17 by tchoquet         ###   ########.fr       */
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
	t_wh		window_size;
	void		*window_buff;

	if (load_cubfile("test.cub", &setup_data.cub) != 0)
		return (cub_perror("test.cub"), 1);
	setup_data.window = new_window("cub3d", (t_wh){WIDTH, HEIGHT});
	set_destructor(setup_data.window, (t_func){
		(void (*)(void*)) & clean_stpdata, &setup_data});
	set_backcolor(setup_data.window, 0x00A0A0A0);
	start_main_loop((t_func){(void (*)(void *)) & main_loop, &setup_data});
	return (0);
}

void	main_loop(t_stpdata *stpdata)
{
}

void	clean_stpdata(t_stpdata *stpdata)
{
	free_cub_file(&stpdata->cub);
}
