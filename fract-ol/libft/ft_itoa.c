/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:37:12 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/06 16:14:29 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digit_count(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t			digit_count;
	char			*str;
	unsigned int	abs_n;

	digit_count = get_digit_count(n);
	str = malloc(digit_count + 1);
	if (str == NULL)
		return (NULL);
	str[digit_count] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		abs_n = -n;
	}
	else
		abs_n = n;
	while (abs_n > 0)
	{
		str[--digit_count] = (abs_n % 10) + '0';
		abs_n /= 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}
