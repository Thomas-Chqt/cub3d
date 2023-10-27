/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:00:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/29 14:03:26 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lstint_new(int val)
{
	t_list	*new_node;

	new_node = ft_lstnew(NULL);
	if (new_node != NULL)
	{
		new_node->data = malloc(sizeof(int));
		if (new_node->data != NULL)
		{
			*((int *)new_node->data) = val;
			return (new_node);
		}
		free(new_node);
	}
	return (NULL);
}
