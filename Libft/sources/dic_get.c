/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:59:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 15:31:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

typedef t_bool	(*t_is_equal_func)(void *, void *);

static t_bool				is_equal_wapper(void *el, void *data);

void	*dic_get(t_dictionary dict, void *key,
			t_bool (*is_key_equal)(void *, void *))
{
	t_dictionary_int	*dict_int;
	t_uint64			hashed_key;
	t_list_dict			*found_lst_node;

	dict_int = (t_dictionary_int *)dict;
	if (!dic_isvalid(dict) || key == NULL || is_key_equal == NULL)
		return (NULL);
	hashed_key = dict_int->hash_func(key, dict_int->size);
	found_lst_node
		= (t_list_dict *)lst_chr((t_list *)dict_int->vals[hashed_key],
			&is_equal_wapper, (void *[2]){key, is_key_equal});
	if (found_lst_node == NULL)
		return (NULL);
	return (dict_int->dup_val(found_lst_node->data->val));
	return (0);
}

static t_bool	is_equal_wapper(void *el, void *data)
{
	t_is_equal_func	is_key_equal;

	is_key_equal = ((void **)data)[1];
	return (is_key_equal(((t_dict_el *)el)->key, ((void **)data)[0]));
}
