/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_setfreefunc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:33:37 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/24 22:37:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	dic_setfreefunc(t_dictionary dict,
			void (*free_key)(void *), void (*free_val)(void *))
{
	((t_dictionary_int *)dict)->free_key = free_key;
	((t_dictionary_int *)dict)->free_val = free_val;
}
