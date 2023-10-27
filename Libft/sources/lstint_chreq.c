/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstint_chreq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:12:43 by tchoquet          #+#    #+#             */
/*   Updated: 2023/09/29 15:15:30 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_list	*lstint_chreq(t_list *lst, int n)
{
	return (lst_chr(lst, (t_bool (*)(void *, void *)) & is_equal, &n));
}
