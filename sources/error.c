/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:15:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/05 13:56:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static void	cub_pferror(void);
static void	cub_pmerror(void);

void	set_error(int code)
{
	if (code < 150)
	{
		*g_error() = code;
		return ;
	}
	if (code < 200)
	{
		*g_error() = 0;
		g_map_err()->code = 0;
		g_file_err()->code = code;
		return ;
	}
	if (code < 250)
	{
		*g_error() = 0;
		g_file_err()->code = 0;
		g_map_err()->code = code;
		return ;
	}
}

void	cub_perror(char *str)
{
	ft_putstr_fd("Error\ncub3d: ", STDERR_FILENO);
	if (g_file_err()->code != 0)
		return (cub_pferror());
	if (g_map_err()->code != 0)
		return (cub_pmerror());
	if (*g_error() == MALLOC_ERROR)
		return ((void)ft_putendl_fd("malloc error", STDERR_FILENO));
	perror(str);
}

static void	cub_pferror(void)
{
	ft_putstr_fd(g_file_err()->file, STDERR_FILENO);
	ft_putstr_fd(": line ", STDERR_FILENO);
	ft_putnbr_fd(g_file_err()->line, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (g_file_err()->code == PARSING_ERROR)
		return ((void)ft_putendl_fd("parsing error", STDERR_FILENO));
	if (g_file_err()->code == MULTI_TEXT_ERROR)
		return ((void)ft_putendl_fd("texture redefinition", STDERR_FILENO));
	if (g_file_err()->code == MULTI_COL_ERROR)
		return ((void)ft_putendl_fd("color redefinition", STDERR_FILENO));
	if (g_file_err()->code == UNEP_EOF_ERROR)
		return ((void)ft_putendl_fd("unexpected EOF", STDERR_FILENO));
	if (g_file_err()->code == WRONG_CHAR_ERROR)
		return ((void)ft_putendl_fd("bad character", STDERR_FILENO));
	if (g_file_err()->code == BIG_MAP_ERROR)
		return ((void)ft_putendl_fd("map too big", STDERR_FILENO));
	if (g_file_err()->code == LONG_LINE_ERROR)
		return ((void)ft_putendl_fd("line too long", STDERR_FILENO));
}

static void	cub_pmerror(void)
{
	ft_putstr_fd("map: row ", STDERR_FILENO);
	ft_putnbr_fd(g_map_err()->row, STDERR_FILENO);
	ft_putstr_fd(", column ", STDERR_FILENO);
	ft_putnbr_fd(g_map_err()->collum, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (g_map_err()->code == NOT_CLOSED_ERROR)
		return ((void)ft_putendl_fd("map not closed", STDERR_FILENO));
}
