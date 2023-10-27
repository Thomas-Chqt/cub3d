/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_lastnext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:17:27 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/30 12:33:10 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	**lst_lastnext(t_list **head)
{
	t_list	**nextptr;

	nextptr = head;
	if (nextptr == NULL)
		return (NULL);
	while (*nextptr != NULL && (*nextptr)->next != NULL)
		nextptr = &(*nextptr)->next;
	return (nextptr);
}
