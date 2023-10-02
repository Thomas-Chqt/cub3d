/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:44:11 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/02 21:44:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_data(int fd, t_cubfile *cub)
{
	int		ret_code;

	cub_file_err()->line = 1;
	while (cub->parsed_flags != ALL_PARSED_FLAG)
	{
		ret_code = parse_next_data(fd, cub);
		if (ret_code != 0 && ret_code != PARSING_ERROR)
			return (ret_code);
		cub_file_err()->line++;
	}
	return (0);
}

int	parse_next_data(int fd, t_cubfile *cub)
{
	char	*line;
	int		ret_code;

	line = get_next_line(fd);
	if (line == NULL)
		return (cub_perror_file("Unexpected EOF"), 1);
	ret_code = parse_no_text(line, cub);
	if (ret_code != PARSING_ERROR)
		return (free(line), ret_code);
	ret_code = parse_so_text(line, cub);
	if (ret_code != PARSING_ERROR)
		return (free(line), ret_code);
	ret_code = parse_we_text(line, cub);
	if (ret_code != PARSING_ERROR)
		return (free(line), ret_code);
	ret_code = parse_ea_text(line, cub);
	if (ret_code != PARSING_ERROR)
		return (free(line), ret_code);
	ret_code = parse_f_col(line, cub);
	if (ret_code != PARSING_ERROR)
		return (free(line), ret_code);
	ret_code = parse_c_col(line, cub);
	if (ret_code != PARSING_ERROR)
		return (free(line), ret_code);
	return (free(line), PARSING_ERROR);
}
