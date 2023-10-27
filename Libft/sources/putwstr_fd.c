/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwstr_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:28:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/13 16:35:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	putwstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		if ((*s & 0x80) == 0x00)
			(void)write(fd, s++, 1);
		if ((*s & 0xe0) == 0xc0)
		{
			(void)write(fd, s, 2);
			s += 2;
		}
		if ((*s & 0xf0) == 0xe0)
		{
			(void)write(fd, s, 3);
			s += 3;
		}
		if ((*s & 0xf8) == 0xf0)
		{
			(void)write(fd, s, 4);
			s += 4;
		}
	}
}
