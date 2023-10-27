/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_toarrmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:19:00 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/24 16:28:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	*data_dup(void *data);

int	*lstint_toarrmap(t_list *lst)
{
	t_array	array;

	array = lst_toarrmap(lst, sizeof(int), &data_dup, NULL);
	return (array.buff);
}

static void	*data_dup(void *data)
{
	return (mem_dup(data, sizeof(int)));
}
