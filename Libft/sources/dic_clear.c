/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:40:02 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 15:31:53 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	lstdict_clear(t_list_dict **lst, void (*free_key)(void *),
			void (*free_val)(void *));

void	dic_clear(t_dictionary dict)
{
	t_dictionary_int	*dict_int;
	t_uint64			i;

	if (!dic_isvalid(dict))
		return ;
	dict_int = (t_dictionary_int *)dict;
	i = 0;
	while (i < dict_int->size)
	{
		lstdict_clear(dict_int->vals + i, dict_int->free_key,
			dict_int->free_val);
		i++;
	}
	free(dict_int->vals);
	free(dict);
}

void	lstdict_clear(t_list_dict **lst, void (*free_key)(void *),
			void (*free_val)(void *))
{
	t_list_dict	*watched;
	t_list_dict	*temp;

	watched = *lst;
	while (watched != NULL)
	{
		free_key(watched->data->key);
		free_val(watched->data->val);
		free(watched->data);
		temp = watched->next;
		free(watched);
		watched = temp;
	}
	(*lst) = NULL;
}
