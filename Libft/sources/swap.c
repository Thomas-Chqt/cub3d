/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:55:59 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/15 11:10:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	swap_uint32(t_uint32 *a, t_uint32 *b);
static void	swap_ptr(void **a, void **b);

void	swap(void *a, void *b, size_t el_size)
{
	void	*temp;

	if (el_size == sizeof(t_uint32))
		return (swap_uint32((t_uint32 *)a, (t_uint32 *)b));
	if (el_size == sizeof(void *))
		return (swap_ptr((void **)a, (void **)b));
	temp = malloc(el_size);
	if (temp == NULL)
		return ;
	ft_memmove(temp, a, el_size);
	ft_memmove(a, b, el_size);
	ft_memmove(b, temp, el_size);
	free(temp);
}

static void	swap_uint32(t_uint32 *a, t_uint32 *b)
{
	t_uint32	temp;

	ft_memmove(&temp, a, sizeof(t_uint32));
	ft_memmove(a, b, sizeof(t_uint32));
	ft_memmove(b, &temp, sizeof(t_uint32));
}

static void	swap_ptr(void **a, void **b)
{
	void	*temp;

	ft_memmove(&temp, a, sizeof(void *));
	ft_memmove(a, b, sizeof(void *));
	ft_memmove(b, &temp, sizeof(void *));
}
