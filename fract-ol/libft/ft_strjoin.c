/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:37:12 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/07 12:42:44 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strjoin_check(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (1);
	else if (!s2)
		return (1);
	else
		return (0);
}

static char	*ft_strjoin_return(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_n;
	size_t	s2_n;
	char	*array;
	size_t	i;

	if (ft_strjoin_check(s1, s2))
		return (ft_strjoin_return(s1, s2));
	s1_n = ft_strlen(s1);
	s2_n = ft_strlen(s2);
	array = (char *)malloc(s1_n + s2_n + 1);
	if (!array)
		return (NULL);
	i = -1;
	while (++i < s1_n)
		array[i] = s1[i];
	while (i < s1_n + s2_n)
	{
		array[i] = s2[i - s1_n];
		i++;
	}
	array[i] = '\0';
	return (array);
}
