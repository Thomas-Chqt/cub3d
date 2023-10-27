/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicstrstr_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:05:01 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 15:34:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

static t_bool	is_equal_func(void *a, void *b);

char	*dicstrstr_get(t_dictionary dict, char *key)
{
	char	**str_ptr;
	char	*str;

	str_ptr = (char **)dic_get(dict, &key, &is_equal_func);
	if (str_ptr == NULL)
		return (NULL);
	str = *str_ptr;
	free(str_ptr);
	return (str);
}

static t_bool	is_equal_func(void *a, void *b)
{
	if (ft_strncmp(*((const char **)a), *((const char **)b),
			ft_strlen(*((const char **)a))) == 0)
		return (true);
	else
		return (false);
}
