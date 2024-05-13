/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:37:12 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/07 12:30:28 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if ((len == 0 && *needle != 0) || (len == 0 && haystack == NULL))
		return (NULL);
	if (ft_strlen(needle) == 0 || len == 0)
		return ((char *)&haystack[0]);
	i = 0;
	needle_len = ft_strlen(needle);
	if (!needle)
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{
		j = 0;
		while (haystack[i + j] != 0 && needle[j] != 0 && haystack[i
				+ j] == needle[j] && i + j < len)
			j++;
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
