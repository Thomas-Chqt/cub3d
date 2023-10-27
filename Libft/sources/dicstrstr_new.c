/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicstrstr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:40:02 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 15:34:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_uint64	hash_func(void *key_ptr, size_t dict_size);
static void		*dup_func(void *ptr);

t_dictionary	dicstrstr_new(size_t size)
{
	t_dictionary	new_dict;

	new_dict = dic_new(size, &hash_func);
	dic_setdupfunc(new_dict, &dup_func, &dup_func);
	dic_setfreefunc(new_dict, &free_str_ptr, &free_str_ptr);
	return (new_dict);
}

static t_uint64	hash_func(void *key_ptr, size_t dict_size)
{
	char		*key;
	t_uint64	hash;
	t_uint64	i;
	size_t		key_len;

	key = *((char **)key_ptr);
	hash = 7;
	key_len = ft_strlen(key);
	i = 0;
	while (i < key_len)
	{
		hash = (hash * 31) + key[i];
		i++;
	}
	return (hash % dict_size);
}

static void	*dup_func(void *ptr)
{
	char	*str;
	char	*duped_str;
	char	**duped_str_ptr;

	str = *((char **)ptr);
	duped_str = ft_strdup(str);
	if (duped_str == NULL)
		return (NULL);
	duped_str_ptr = malloc(sizeof(char *));
	if (duped_str_ptr == NULL)
		free(duped_str);
	else
		*duped_str_ptr = duped_str;
	return (duped_str_ptr);
}
