/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:30:24 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/05 14:35:50 by tchoquet         ###   ########.fr       */
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

int	main(void)
{
	t_stpdata	setup_data;
	t_wh		window_size;
	void		*window_buff;

	setup_data = (t_stpdata){};
	if (load_cubfile("test.cub", &setup_data.cub) != 0)
		return (cub_perror("test.cub"), 1);
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

	t_pos	pos = {1, 1};

	for (size_t y = 0; y < stpdata->cub.size.h; y++)
	{
		for (size_t x = 0; x < stpdata->cub.size.w; x++)
		{
			if (stpdata->cub.tiles[y][x] > wal)
				put_rect(stpdata->window_ctx, (t_wh){30, 30}, pos, WHITE);
			else if (stpdata->cub.tiles[y][x] == wal)
				put_rect(stpdata->window_ctx, (t_wh){30, 30}, pos, BLACK);
			pos.x += 31;
		}
		pos.x = 1;
		pos.y += 31;
	}
}

void	clean_stpdata(t_stpdata *stpdata)
{
	del_2d_ctx(stpdata->window_ctx);
	free_cub_file(&stpdata->cub);
}
