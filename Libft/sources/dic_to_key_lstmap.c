/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_to_key_lstmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:14:21 by tchoquet          #+#    #+#             */
/*   Updated: 2023/08/05 16:17:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_list	*dic_to_key_lstmap(t_dictionary dict)
{
	t_dictionary_int	*dict_int;
	t_list				*val_lst;
	t_list				*temp_lst;
	t_uint64			i;

	val_lst = NULL;
	temp_lst = NULL;
	if (!dic_isvalid(dict))
		return (NULL);
	dict_int = (t_dictionary_int *)dict;
	i = -1;
	while (++i < dict_int->size)
	{
		if (dict_int->vals[i] != NULL)
		{
			temp_lst = lstdic_tokeymap(dict_int->vals[i], dict_int);
			if (temp_lst == NULL)
			{
				ft_lstclear(&val_lst, dict_int->free_val);
				return (NULL);
			}
			ft_lstadd_back(&val_lst, temp_lst);
		}
	}
	return (val_lst);
}
