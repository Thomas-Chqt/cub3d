/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdict_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:22:15 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/05 14:26:50 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

static t_list_dict	*ft_lstclear_wrap(t_list_dict **lst,
						t_dictionary_int *funcs);

t_list_dict	*lstdict_dup(t_list_dict *lst, t_dictionary_int *funcs)
{
	t_list_dict		*new_lst;
	t_list_dict		*lst_current;
	t_list_dict		*new_lst_current;

	if (lst == NULL || dic_isvalid((t_dictionary) funcs))
		return (NULL);
	new_lst = lstdict_nodedup(lst, funcs);
	if (new_lst == NULL)
		return (NULL);
	lst_current = lst->next;
	new_lst_current = new_lst;
	while (lst_current != NULL)
	{
		new_lst_current->next = lstdict_nodedup(lst_current, funcs);
		if (new_lst_current->next == NULL)
			return (ft_lstclear_wrap(&new_lst, funcs));
		lst_current = lst_current->next;
		new_lst_current = new_lst_current->next;
	}
	return (new_lst);
}

static t_list_dict	*ft_lstclear_wrap(t_list_dict **lst,
						t_dictionary_int *funcs)
{
	lstdic_clear(lst, funcs);
	return (NULL);
}
