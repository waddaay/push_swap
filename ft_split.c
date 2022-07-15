/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:14:17 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/15 03:05:22 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*allocate_and_fill(char *s, char c)
{
	char	*ptr;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

char	**free_all(char **ptr, int i)
{
	while (--i >= 0)
		free(ptr[i]);
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ptr;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	ptr = (char **)malloc (sizeof(char *) * (word_count(str, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < word_count((char *)s, c))
	{
		while (*str && *str == c)
			str++;
		ptr[i] = allocate_and_fill(str, c);
		if (!ptr[i])
			return (free_all(ptr, i));
		while (*str && *str != c)
			str++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
