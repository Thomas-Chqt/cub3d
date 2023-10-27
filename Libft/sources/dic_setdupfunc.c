/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_setdupfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:37:25 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/24 22:38:21 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	dic_setdupfunc(t_dictionary dict,
			void *(*dup_key)(void *), void *(*dup_val)(void *))
{
	((t_dictionary_int *)dict)->dup_key = dup_key;
	((t_dictionary_int *)dict)->dup_val = dup_val;
}
