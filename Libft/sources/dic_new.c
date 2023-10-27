/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:25:09 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 01:33:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_dictionary	dic_new(size_t size,
					t_uint64 (*hash_func)(void *key, size_t dict_size))
{
	t_dictionary_int	*new_dic;

	if (size == 0 || hash_func == NULL)
		return ((t_dictionary) NULL);
	new_dic = malloc(sizeof(t_dictionary_int));
	if (new_dic == NULL)
		return ((t_dictionary) NULL);
	*new_dic = (t_dictionary_int){
		.size = size,
		.hash_func = hash_func,
		.vals = ft_calloc(size, sizeof(t_list_dict *))
	};
	if (new_dic->vals == NULL)
		free_null((void **)&new_dic);
	return ((t_dictionary)new_dic);
}
