/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torad.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:19:38 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/26 16:22:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#define _USE_MATH_DEFINES
#include <math.h>

float	torad(float angle)
{
	return (angle * M_PI / 180);
}
