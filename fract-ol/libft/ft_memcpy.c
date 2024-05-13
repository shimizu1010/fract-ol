/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:37:12 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/06 16:09:16 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
	{
		return (NULL);
	}
	char *p1 = (char *)dest;
	const char *p2 = (const char *)src;
	while (n-- > 0)
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	return (dest);
} */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*udst;
	unsigned char	*usrc;

	if (!dst && !src)
		return (NULL);
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (dst);
}
