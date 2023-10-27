/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:56:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/04 14:58:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *));

t_list	*lst_dup(t_list *lst, void *(*data_dup)(void *), void (*del)(void *))
{
	t_list		*new_lst;
	t_list		*lst_current;
	t_list		*new_lst_current;

	if (lst == NULL || data_dup == NULL)
		return (NULL);
	new_lst = lst_nodedup(lst, data_dup);
	if (new_lst == NULL)
		return (NULL);
	lst_current = lst->next;
	new_lst_current = new_lst;
	while (lst_current != NULL)
	{
		new_lst_current->next = lst_nodedup(lst_current, data_dup);
		if (new_lst_current->next == NULL)
			return (ft_lstclear_wrap(&new_lst, del));
		lst_current = lst_current->next;
		new_lst_current = new_lst_current->next;
	}
	return (new_lst);
}

static t_list	*ft_lstclear_wrap(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}
