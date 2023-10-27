/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdic_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:24:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/05 14:26:28 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	lstdic_clear(t_list_dict **lst, t_dictionary_int *funcs)
{
	t_list_dict	*watched;
	t_list_dict	*temp;

	watched = *lst;
	while (watched != NULL)
	{
		if (watched->data != NULL)
		{
			funcs->free_key(watched->data->key);
			funcs->free_val(watched->data->val);
			free(watched->data);
		}
		temp = watched->next;
		free(watched);
		watched = temp;
	}
	(*lst) = NULL;
}
