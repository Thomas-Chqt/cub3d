/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split_on_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:43:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/06 11:55:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

char	**str_split_on_first(const char *str, char c)
{
	char		**splited_str;
	t_uint64	i;

	if (str == NULL)
		return (NULL);
	splited_str = ft_calloc(3, sizeof(char *));
	if (splited_str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	splited_str[0] = ft_substr(str, 0, i);
	if (splited_str[0] != NULL)
	{
		if (str[i] == '\0')
			return (splited_str);
		splited_str[1] = ft_strdup(str + (i + 1));
		if (splited_str[1] != NULL)
			return (splited_str);
	}
	free_splited_str(splited_str);
	return (NULL);
}
