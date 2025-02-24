/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:16:54 by ekashirs          #+#    #+#             */
/*   Updated: 2025/02/24 17:23:40 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>


static int	check_memory_allocation(char **array, int position, size_t size)
{
	int	i;

	i = 0;
	array[position] = malloc(size);
	if (array[position] == NULL)
	{
		while (i <= position)
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (1);
	}
	return (0);
}

static int	fill_arr_from_second(char **array, char const *str, char separator)
{
	size_t	len;
	int		i;

	i = 1;
	while (*str)
	{
		len = 0;
		while (*str == separator && *str)
			str++;
		while (*str != separator && *str)
		{
			len++;
			str++;
		}
		if (len)
		{
			if (check_memory_allocation(array, i, len + 1))
				return (1);
			else
				ft_strlcpy(array[i], str - len, len + 1);
		}
		i++;
	}
	return (0);
}

static size_t	count_words(char const *str, char separator)
{
	size_t	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == separator)
			str++;
		if (*str)
			count++;
		while (*str != separator && *str)
			str++;
	}
	return (count);
}

char	**split_parser(char const *str, char separator)
{
	size_t	word_count;
	char	**array;

	if (str == NULL)
		return (NULL);
	word_count = count_words(str, separator);
	array = malloc(sizeof(char *) * (word_count + 2));
	if (array == NULL)
		return (NULL);
	array[word_count] = NULL;
	array[0] = "\0";
	if (fill_arr_from_second(array, str, separator))
		return (NULL);
	return (array);
}
