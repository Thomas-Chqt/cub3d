/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/02 21:38:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef DEBUG

__attribute__((destructor))
static void	destructor(void)
{
	print_report();
	system("leaks -q cub3d_debug");
}

#endif // DEBUG

int	main(void)
{
	t_stpdata	setup_data;
	t_wh		window_size;
	void		*window_buff;

	setup_data = (t_stpdata){};
	setup_data.cub = load_cubfile("test.cub");
	if (setup_data.cub.tiles == NULL)
		return (clean_stpdata(&setup_data), 1);
	window_size = (t_wh){WIDTH, HEIGHT};
	setup_data.window = new_window("cub3d", window_size);
	window_buff = get_pixel_buffer(setup_data.window);
	setup_data.window_ctx = new_2d_ctx_buf(window_buff, window_size);
	add_destructor(setup_data.window, (t_func){
		(void (*)(void*)) & clean_stpdata, &setup_data});
	start_main_loop((t_func){(void (*)(void *)) & main_loop, &setup_data});
	return (0);
}

void	main_loop(t_stpdata *stpdata)
{
	fill_2d_ctx(stpdata->window_ctx, 0x00A0A0A0);
}

void	clean_stpdata(t_stpdata *stpdata)
{
	del_2d_ctx(stpdata->window_ctx);
	free_cubfile(stpdata->cub);
}
