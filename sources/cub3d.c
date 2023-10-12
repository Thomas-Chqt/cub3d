/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:44:14 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/11 23:10:19 by tchoquet         ###   ########.fr       */
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
		return (set_error((0b0000 << 28) | BAD_ARGS), -1);
	if (create_window("cub3d", (t_vec2i){WIDTH, HEIGHT}) != 0)
		return (set_error((0b0000 << 28) | MALLOC), -1);
	set_destructor(&clean, NULL);
	if (load_cubfile(argv[1]) != 0)
		return (clean(NULL), -1);
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
	t_cub3d	*cub;
	int		i;

	(void)none;
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
	free_context(cub->p_ctx);
	delete_window();
}