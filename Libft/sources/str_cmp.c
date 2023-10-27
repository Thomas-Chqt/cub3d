/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:39:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/22 13:08:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	str_cmp(const char *s1, const char *s2)
{
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL && s2 != NULL)
		return (-1);
	if (s1 != NULL && s2 == NULL)
		return (1);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
