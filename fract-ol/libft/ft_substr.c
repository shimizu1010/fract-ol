/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:41:59 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/16 14:15:42 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
	{
		substr = malloc(1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
	}
	else
	{
		if (start + len > s_len)
			len = s_len - start;
		substr = malloc(len + 1);
		if (substr == NULL)
			return (NULL);
		ft_strlcpy(substr, s + start, len + 1);
	}
	return (substr);
}
