/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:37:12 by aoshimiz          #+#    #+#             */
/*   Updated: 2023/06/06 17:51:59 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static char	*get_next_word(const char **s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while ((*s)[len] != c && (*s)[len] != '\0')
		len++;
	word = (char *)malloc(len + 1);
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[len] = '\0';
	*s += len;
	return (word);
}

static char	**allocate_words(char const *s, char c, size_t *word_count)
{
	char	**words;

	if (!s)
		return (NULL);
	*word_count = get_word_count(s, c);
	words = (char **)malloc((*word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**words;
	size_t	i;

	words = allocate_words(s, c, &word_count);
	if (words == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		words[i] = get_next_word(&s, c);
		if (words[i] == NULL)
		{
			while (i > 0)
				free(words[--i]);
			free(words);
			return (NULL);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}
