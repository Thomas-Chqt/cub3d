/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_qcksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:58:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/15 10:32:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static int	partition(t_array array, t_bool (*is_sort)(void *a, void *b));

void	arr_qcksort(t_array array, t_bool (*is_sort)(void *a, void *b))
{
	size_t	pivot_index;

	if (array.buff == NULL || array.len < 2 || is_sort == NULL)
		return ;
	if (array.len == 2 && is_sort(array.buff, el(array, 1)) == true)
		return ;
	if (array.len != 2)
	{
		pivot_index = partition(array, is_sort);
		arr_qcksort((t_array){array.buff, pivot_index, array.el_size}, is_sort);
		arr_qcksort((t_array){el(array, pivot_index + 1),
			array.len - (pivot_index + 1), array.el_size}, is_sort);
	}
	else
		swap(array.buff, el(array, 1), array.el_size);
}

static int	partition(t_array array, t_bool (*is_sort)(void *a, void *b))
{
	void	*pivot_value;
	size_t	i;
	size_t	j;

	pivot_value = el(array, array.len - 1);
	i = 0;
	j = 0;
	while (j < (array.len - 1))
	{
		if (is_sort(el(array, j), pivot_value) == true)
		{
			swap(el(array, i), el(array, j), array.el_size);
			i++;
		}
		j++;
	}
	swap(el(array, i), el(array, array.len - 1), array.el_size);
	return (i);
}
