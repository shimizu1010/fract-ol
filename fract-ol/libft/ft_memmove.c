/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:37:12 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/06 16:08:37 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
	return (NULL);
	char *tmp;
	const char *s;
	tmp = (char *)dest;
	s = (char *)src;
	if (dest <= src)
	{
		while (n--)
			*tmp++ = *s++;
	}
	else
	{
		tmp += n;
		s += n;
		while (n--)
			*--tmp = *--s;
	}
	return (dest);
} */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return (dst);
}
