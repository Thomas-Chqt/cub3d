/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/12 13:27:55 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static void	print_pre_msg(t_uint8 bits);
static void	print_msg(t_uint32 code);
static void	print_msg2(t_uint32 code);

t_cuberr	*cub_error(void)
{
	static t_cuberr	cub3d_error = {0};

	return (&cub3d_error);
}

void	cub_perror(void)
{
	print_pre_msg(cub_error()->code >> 28);
	print_msg(cub_error()->code & 0x0FFFFFFF);
}

static void	print_pre_msg(t_uint8 bits)
{
	ft_putstr_fd("Error\ncub3d: ", STDERR_FILENO);
	if (((bits >> 3) & 1) == 1)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (((bits >> 2) & 1) == 1)
	{
		ft_putnbr_fd(cub_error()->y, STDERR_FILENO);
		if (((bits >> 1) & 1) == 1)
		{
			ft_putstr_fd(":", STDERR_FILENO);
			ft_putnbr_fd(cub_error()->x, STDERR_FILENO);
		}
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if ((bits & 1) == 1)
	{
		ft_putstr_fd(cub_error()->texf, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
}

static void	print_msg(t_uint32 code)
{
	if (code == MALLOC)
		return (ft_putendl_fd("Malloc Erorr", STDERR_FILENO));
	if (code == BAD_ARGS)
		return (ft_putendl_fd("Bad arguments", STDERR_FILENO));
	if (code == PERROR)
		return (perror(""));
	if (code == NO_PLAYER)
		return (ft_putendl_fd("No player start", STDERR_FILENO));
	if (code == PARSING)
		return (ft_putendl_fd("Parsing error", STDERR_FILENO));
	if (code == MULTI_TEXT)
		return (ft_putendl_fd("Texture redefinition", STDERR_FILENO));
	if (code == MULTI_COL)
		return (ft_putendl_fd("Color redefinition", STDERR_FILENO));
	if (code == UNEXP_EOF)
		return (ft_putendl_fd("Unexpected EOF", STDERR_FILENO));
	if (code == WRONG_CHAR)
		return (ft_putendl_fd("Bad character", STDERR_FILENO));
	if (code == BIG_MAP)
		return (ft_putendl_fd("Map too big", STDERR_FILENO));
	if (code == LONG_LINE)
		return (ft_putendl_fd("Line too long", STDERR_FILENO));
	if (code == DOUBLE_P)
		return (ft_putendl_fd("Multiple player start", STDERR_FILENO));
	print_msg2(code);
}

static void	print_msg2(t_uint32 code)
{
	if (code == NOT_CLOSE)
		return (ft_putendl_fd("Map not closed", STDERR_FILENO));
}
