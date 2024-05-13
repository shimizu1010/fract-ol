/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:37:12 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/13 19:13:39 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*process_sign(const char *str, int *sign)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

//process signで飛ばし切って、符号を決定する。
//余りがlong_max/10が大きい場合とあまりがlong_max/10と同じでかつ次の数字がlong_maxの一の位よりも大きい
int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	str = process_sign(str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		if (res > LONG_MAX / 10 || (res == LONG_MAX / 10 && *str
				- '0' > LONG_MAX % 10))
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			return ((int)LONG_MIN);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)sign * res);
}
