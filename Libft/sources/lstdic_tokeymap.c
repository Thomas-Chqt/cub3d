/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdic_tokeymap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:48:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/05 16:17:03 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

static t_list	*create_nodes(void *v_data, void *v_funcs);

t_list	*lstdic_tokeymap(t_list_dict *lst, t_dictionary_int *funcs)
{
	return (lst_map((t_list *)lst, &create_nodes, funcs, &free_str_ptr));
}

static t_list	*create_nodes(void *v_data, void *v_funcs)
{
	t_list				*new_node;
	t_dict_el			*data;
	t_dictionary_int	*funcs;

	data = (t_dict_el *)v_data;
	funcs = (t_dictionary_int *)v_funcs;
	new_node = ft_lstnew(NULL);
	if (new_node != NULL)
	{
		if (data->key == NULL)
			return (new_node);
		new_node->data = funcs->dup_key(data->key);
		if (new_node->data != NULL)
			return (new_node);
		free(new_node);
	}
	return (NULL);
}
