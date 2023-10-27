/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_delifeq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:09:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/29 14:12:19 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

void	lstint_delifeq(t_list **head, int n)
{
	lst_delif(head,
		&free_wrap,
		(t_bool (*)(void *, void *)) & is_equal,
		&n);
}
