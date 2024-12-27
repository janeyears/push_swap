/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:47:32 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/27 14:25:42 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	ft_fill_arr(char const *s, char c)
{
	static int	cursor = 0;
	char	*next_str;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while(s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_str = malloc ((len + 1) * sizeof(char));
	if (next_str == NULL)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_str[i++] = s[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**split(char const *s, char c)
{
	size_t	word_count;
	char	**arr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = ft_countword(s, c);
	arr = malloc((word_count + 2) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i = 0)
		{
			arr[i] = malloc(sizeof(char));
			if (arr[i] == NULL)
				return (NULL);
			arr[i++][0] = '\0';
			continue;
		}
		arr[i++] = ft_fill_arr(s, c);
	}
	arr[i] = NULL;
	return (arr);
}
