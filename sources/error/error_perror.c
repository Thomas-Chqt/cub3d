/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_perror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:03:20 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 15:44:31 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static void	cub_perror2(void);
static void	cub_perror3(void);
static void	cub_perror4(void);
static void	cub_perror5(void);

void	cub_perror(void)
{
	ft_putstr_fd("Error\ncub3d: ", STDERR_FILENO);
	if (cub_error()->code == BAD_ARGS_ERROR)
	{
		ft_putendl_fd("Bad arguments", STDERR_FILENO);
	}
	if (cub_error()->code == MALLOC_ERROR)
	{
		ft_putendl_fd("Malloc error", STDERR_FILENO);
	}
	if (cub_error()->code == CUBF_OPEN_ERROR)
	{
		perror(cub_error()->cubf);
	}
	if (cub_error()->code == UNEXP_EOF_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->line, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd("Unexpected EOF", STDERR_FILENO);
	}
	cub_perror2();
}

static void	cub_perror2(void)
{
	if (cub_error()->code == PARSING_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->line, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd("Parsing error", STDERR_FILENO);
	}
	if (cub_error()->code == MULTI_TEX_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->line, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd("Texture redefinition", STDERR_FILENO);
	}
	if (cub_error()->code == TEXF_LOAD_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->line, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror(cub_error()->texf);
	}
	cub_perror3();
}

static void	cub_perror3(void)
{
	if (cub_error()->code == MULTI_COL_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->line, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd("Color redefinition", STDERR_FILENO);
	}
	if (cub_error()->code == LONG_LINE_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->line, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd("Line too long", STDERR_FILENO);
	}
	if (cub_error()->code == BIG_MAP_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd("Map too big", STDERR_FILENO);
	}
	cub_perror4();
}

static void	cub_perror4(void)
{
	if (cub_error()->code == DOUBLE_P_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->line, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->column, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd("Multiple player start position", STDERR_FILENO);
	}
	if (cub_error()->code == BAD_CHAR_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->line, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->column, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd("Bad character", STDERR_FILENO);
	}
	cub_perror5();
}

static void	cub_perror5(void)
{
	if (cub_error()->code == NO_P_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putstr_fd(": map: ", STDERR_FILENO);
		ft_putendl_fd("No player start position", STDERR_FILENO);
	}
	if (cub_error()->code == NOT_CLOSE_ERROR)
	{
		ft_putstr_fd(cub_error()->cubf, STDERR_FILENO);
		ft_putstr_fd(": map:", STDERR_FILENO);
		ft_putnbr_fd(cub_error()->line, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(cub_error()->column, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd("Map not closed", STDERR_FILENO);
	}
}
