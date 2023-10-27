/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_isvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:40:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/27 15:32:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

t_bool	dic_isvalid(t_dictionary dict)
{
	t_dictionary_int	*dict_int;

	dict_int = (t_dictionary_int *)dict;
	if (dict_int->size < 1)
		return (false);
	if (dict_int->hash_func == NULL)
		return (false);
	if (dict_int->free_key == NULL)
		return (false);
	if (dict_int->dup_key == NULL)
		return (false);
	if (dict_int->free_val == NULL)
		return (false);
	if (dict_int->dup_val == NULL)
		return (false);
	if (dict_int->vals == NULL)
		return (false);
	return (true);
}
