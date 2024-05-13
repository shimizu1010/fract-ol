/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:37:12 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/16 14:09:09 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size && SIZE_MAX / count < size)
		return (NULL);
	if (count == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr != NULL)
		{
			ft_memset(ptr, 0, 1);
			return (ptr);
		}
		else
			return (NULL);
	}
	ptr = malloc(count * size);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, count * size);
		return (ptr);
	}
	else
		return (NULL);
}
