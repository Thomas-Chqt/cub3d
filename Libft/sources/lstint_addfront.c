/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_addfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:52:13 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/27 23:43:56 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	lstint_addfront(t_list **lst, int val)
{
	t_list	*new_node;

	if (lst == NULL)
		return (2);
	new_node = ft_lstnew(NULL);
	if (new_node != NULL)
	{
		new_node->data = malloc(sizeof(int));
		if (new_node->data != NULL)
		{
			*((int *)new_node->data) = val;
			ft_lstadd_front(lst, new_node);
			return (0);
		}
		free(new_node);
	}
	return (1);
}
