/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodouble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:25:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/10 19:21:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static unsigned short	intlen(int n);

double	atodouble(const char *str)
{
	int				entier;
	double			virgule;
	unsigned short	v_len;

	entier = (double)ft_atoi(str);
	virgule = (double)ft_atoi(ft_strchr(str, '.') + 1);
	v_len = intlen((int)virgule);
	while (v_len > 0)
	{
		virgule /= (double)10;
		v_len--;
	}
	if (entier > 0)
		return ((double)entier + virgule);
	return ((double)entier - virgule);
}

static unsigned short	intlen(int n)
{
	unsigned int	nbr;
	unsigned short	len;

	len = 1;
	if (n < 0)
	{
		len++;
		nbr = n * -1;
	}
	else
		nbr = n;
	while ((nbr / 10) > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}
