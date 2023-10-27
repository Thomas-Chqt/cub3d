/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicstrstr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:56:17 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/04 12:02:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_bool	is_equal_func(void *a, void *b);

int	dicstrstr_set(t_dictionary dict, char *key, char *val)
{
	return (dic_set(dict, &key, &val, &is_equal_func));
}

static t_bool	is_equal_func(void *a, void *b)
{
	if (ft_strncmp(*((const char **)a), *((const char **)b),
			ft_strlen(*((const char **)a))) == 0)
		return (true);
	else
		return (false);
}
