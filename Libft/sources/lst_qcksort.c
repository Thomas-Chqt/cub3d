/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_qcksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:12:18 by tchoquet          #+#    #+#             */
/*   Updated: 2023/10/17 19:09:54 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void		lst_qcksort_recuse(t_list *first, t_list *last,
					t_bool (*is_sort)(void *a, void *b));
static t_list	*partition(t_list *first, t_list *last,
					t_bool (*is_sort)(void *a, void *b));
static t_list	*lst_prev(t_list *head, t_list *elem);
static size_t	lst_len_until(t_list *head, t_list *elem);

void	lst_qcksort(t_list *lst, t_bool (*is_sort)(void *a, void *b))
{
	if (lst == NULL)
		return ;
	lst_qcksort_recuse(lst, NULL, is_sort);
}

static void	lst_qcksort_recuse(t_list *first, t_list *last,
				t_bool (*is_sort)(void *a, void *b))
{
	size_t	len;
	t_list	*pivot;

	len = lst_len_until(first, last);
	if (len < 2)
		return ;
	if (len == 2 && is_sort(first->data, first->next->data) == true)
		return ;
	if (len != 2)
	{
		pivot = partition(first, lst_prev(first, last), is_sort);
		lst_qcksort_recuse(first, pivot, is_sort);
		lst_qcksort_recuse(pivot->next, last, is_sort);
	}
	else
		swap(&first->data, &first->next->data, sizeof(void *));
}

static t_list	*partition(t_list *first, t_list *last,
					t_bool (*is_sort)(void *a, void *b))
{
	t_list	*pivot;
	t_list	*i;
	t_list	*j;

	pivot = last;
	i = first;
	j = first;
	while (j != pivot)
	{
		if (is_sort(j->data, pivot->data) == true)
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
