/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:44:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 22:22:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

t_cub3d	*cub3d(void)
{
	static t_cub3d	global_data = {
		.f_color = TRANSP,
		.c_color = TRANSP
	};

	return (&global_data);
}

int	setup(int argc, char *argv[])
{
	if (argc != 2)
		return (set_error(BAD_ARGS_ERROR), -1);
	if (create_window("cub3d", (t_vec2i){WIDTH, HEIGHT}) != 0)
		return (set_error(MALLOC_ERROR), -1);
	set_destructor(&clean, NULL);
	if (load_cubfile(argv[1]) != 0)
		return (clean(NULL), -1);
	if (init_minimap((t_vec2i){WIDTH / 4, HEIGHT / 4}) != 0)
		return (clean(NULL), -1);
	cub3d()->rays_ctx = new_context((t_vec2i){WIDTH / 4, HEIGHT / 4});
	if (cub3d()->rays_ctx == NULL)
		return (clean(NULL), set_error(MALLOC_ERROR), -1);
	return (0);
}

void	loop(void *none)
{
	int	key;

	(void)none;
	while ((poll_key(&key)))
	{
		if (key == W_KEY)
			pmove_fb(0.1f);
		if (key == S_KEY)
			pmove_fb(-0.1f);
		if (key == D_KEY)
			pmove_lr(0.1f);
		if (key == A_KEY)
			pmove_lr(-0.1f);
		if (key == LEFT_KEY)
			protate(-0.1f);
		if (key == RIGHT_KEY)
			protate(0.1f);
	}
	run_dda();
	render_walls();
	render_minimap((t_vec2i){0, 0});
}

void	clean(void *none)
{
	t_cub3d	*cub;
	int		i;

	(void)none;
	delete_window();
	cub = cub3d();
	free_context(cub->no_tex);
	free_context(cub->so_tex);
	free_context(cub->we_tex);
	free_context(cub->ea_tex);
	i = 0;
	while (cub->map != NULL && i < cub->m_size.y)
		free(cub->map[i++]);
	free(cub->map);
	free_context(cub->mmap_ctx);
	free_context(cub->mmap_p_ctx);
	free_context(cub->rays_ctx);
}
