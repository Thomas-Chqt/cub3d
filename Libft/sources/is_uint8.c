/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_uint8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:22:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/12 17:38:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include <stdint.h>

t_bool	is_uint8(char *str)
{
	uint32_t	nbr;
	uint32_t	i;

	nbr = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > UCHAR_MAX)
			return (false);
		i++;
	}
	if (str[i] != '\0')
		return (false);
	return (true);
}
