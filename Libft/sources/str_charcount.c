/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_charcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:48:03 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/13 11:50:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

size_t	str_charcount(char *str, char c)
{
	size_t		count;
	t_uint64	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
