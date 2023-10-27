/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_qcksort_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:26:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/18 17:29:49 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void		lst_qcksort_recuse_data(t_list *first, t_list *last,
					t_bool (*is_sort)(void *a, void *b, void *data),
					void *data);
static t_list	*partition_data(t_list *first, t_list *last,
					t_bool (*is_sort)(void *a, void *b, void *data),
					void *data);
static t_list	*lst_prev(t_list *head, t_list *elem);
static size_t	lst_len_until(t_list *head, t_list *elem);

void	lst_qcksort_data(t_list *lst,
			t_bool (*is_sort)(void *a, void *b, void *data), void *data)
{
	if (lst == NULL)
		return ;
	lst_qcksort_recuse_data(lst, NULL, is_sort, data);
}

static void	lst_qcksort_recuse_data(t_list *first, t_list *last,
				t_bool (*is_sort)(void *a, void *b, void *data), void *data)
{
	size_t	len;
	t_list	*pivot;

	len = lst_len_until(first, last);
	if (len < 2)
		return ;
	if (len == 2 && is_sort(first->data, first->next->data, data) == true)
		return ;
	if (len != 2)
	{
		pivot = partition_data(first, lst_prev(first, last), is_sort, data);
		lst_qcksort_recuse_data(first, pivot, is_sort, data);
		lst_qcksort_recuse_data(pivot->next, last, is_sort, data);
	}
	else
		swap(&first->data, &first->next->data, sizeof(void *));
}

static t_list	*partition_data(t_list *first, t_list *last,
					t_bool (*is_sort)(void *a, void *b, void *data), void *data)
{
	t_list	*pivot;
	t_list	*i;
	t_list	*j;

	pivot = last;
	i = first;
	j = first;
	while (j != pivot)
	{
		if (is_sort(j->data, pivot->data, data) == true)
		{
			swap(&i->data, &j->data, sizeof(void *));
			i = i->next;
		}
		j = j->next;
	}
	swap(&i->data, &pivot->data, sizeof(void *));
	return (i);
}

static t_list	*lst_prev(t_list *head, t_list *elem)
{
	t_list		*curr;

	if (head == elem)
		return (NULL);
	curr = head;
	while (curr->next != elem)
		curr = curr->next;
	return (curr);
}

static size_t	lst_len_until(t_list *head, t_list *elem)
{
	t_list	*curr;
	size_t	len;

	len = 0;
	curr = head;
	while (curr != elem)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}
