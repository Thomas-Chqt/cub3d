/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:28:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/03 14:55:01 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_bool	is_empty_str(char *str)
{
	t_uint64	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_whitespace(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
