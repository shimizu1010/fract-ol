/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:37:12 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/06 15:57:56 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	k;
	size_t	max_copy;
	size_t	d_n;
	size_t	s_n;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	d_n = ft_strlen(dest);
	s_n = ft_strlen(src);
	if (size <= d_n)
		return (size + s_n);
	max_copy = size - d_n - 1;
	k = 0;
	while (k < max_copy)
	{
		if (src[k] == 0)
			break ;
		dest[d_n + k] = src[k];
		k++;
	}
	dest[k + d_n] = 0;
	return (s_n + d_n);
}
