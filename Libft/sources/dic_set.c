/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:39:34 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 15:33:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

#define INPUT_NOT_VALID 1
#define UNKNOWN_ERROR 2

typedef t_bool	(*t_is_equal_func)(void *, void *);

static t_list_dict	*lstdic_new(t_dictionary_int *funcs, void *key, void *val);
static t_bool		is_equal_wapper(void *el, void *data);

int	dic_set(t_dictionary dict, void *key, void *val,
		t_bool (*is_key_equal)(void *, void *))
{
	t_dictionary_int	*dict_int;
	t_uint64			hashed_key;
	t_list_dict			*found_lst_node;
	t_list				*new_node;

	dict_int = (t_dictionary_int *)dict;
	if (!dic_isvalid(dict) || key == NULL || is_key_equal == NULL)
		return (INPUT_NOT_VALID);
	hashed_key = dict_int->hash_func(key, dict_int->size);
	found_lst_node
		= (t_list_dict *)lst_chr((t_list *)dict_int->vals[hashed_key],
			&is_equal_wapper, (void *[2]){key, is_key_equal});
	if (found_lst_node != NULL)
	{
		dict_int->free_val(found_lst_node->data->val);
		found_lst_node->data->val = dict_int->dup_val(val);
		if (found_lst_node->data->val == NULL)
			return (UNKNOWN_ERROR);
		return (0);
	}
	new_node = (t_list *)lstdic_new(dict_int, key, val);
	if (new_node == NULL)
		return (UNKNOWN_ERROR);
	ft_lstadd_front((t_list **)(dict_int->vals + hashed_key), new_node);
	return (0);
}

static t_list_dict	*lstdic_new(t_dictionary_int *funcs, void *key, void *val)
{
	t_list_dict	*new_node;

	new_node = malloc(sizeof(t_list_dict));
	if (new_node != NULL)
	{
		new_node->next = NULL;
		new_node->data = malloc(sizeof(t_dict_el));
		if (new_node->data != NULL)
		{
			new_node->data->key = funcs->dup_key(key);
			if (new_node->data->key != NULL)
			{
				new_node->data->val = funcs->dup_val(val);
				if (new_node->data->val != NULL)
					return (new_node);
				free(new_node->data->key);
			}
			free(new_node->data);
		}
		free(new_node);
	}
	return (NULL);
}

static t_bool	is_equal_wapper(void *el, void *data)
{
	t_is_equal_func	is_key_equal;

	is_key_equal = ((void **)data)[1];
	return (is_key_equal(((t_dict_el *)el)->key, ((void **)data)[0]));
}
