/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdict_nodedup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:14:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/04 15:21:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_list_dict	*lstdict_nodedup(t_list_dict *node, t_dictionary_int *funcs)
{
	t_list_dict	*duped_node;

	if (node == NULL)
		return (NULL);
	duped_node = ft_calloc(1, sizeof(t_list_dict));
	if (duped_node != NULL)
	{
		if (node->data == NULL)
			return (duped_node);
		duped_node->data = malloc(sizeof(t_dict_el));
		if (duped_node->data != NULL)
		{
			duped_node->data->key = funcs->dup_key(node->data->key);
			if (duped_node->data->key != NULL)
			{
				duped_node->data->val = funcs->dup_val(node->data->val);
				if (duped_node->data->val != NULL)
					return (duped_node);
				free(duped_node->data->key);
			}
			free(duped_node->data);
		}
		free(duped_node);
	}
	return (NULL);
}
