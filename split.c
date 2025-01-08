/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:47:32 by ekashirs          #+#    #+#             */
/*   Updated: 2025/01/08 12:50:22 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <unistd.h>

static void	error_message(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

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

static char	*ft_fill_arr(char *s, char c)
{
	static int	cursor = 0;
	char		*next_str;
	size_t		len;
	int			i;

	i = 0;
	len = 0;
	while (s[cursor] == c)
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

char	**ft_split(char *str, char separator)
{
	int		words_number;
	char	**arr;
	int		i;

	i = 0;
	words_number = ft_countword(str, separator);
	if (!words_number)
		error_message();
	arr = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (arr == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			arr[i] = malloc(sizeof(char));
			if (arr[i] == NULL)
				return (NULL);
			arr[i++][0] = '\0';
			continue ;
		}
		arr[i++] = ft_fill_arr(str, separator);
	}
	arr[i] = NULL;
	return (arr);
}
