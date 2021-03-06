/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbertoni <wbertoni@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:32:23 by wbertoni          #+#    #+#             */
/*   Updated: 2020/10/17 18:34:16 by wbertoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Count how many words a string has,
**  with character c as a space character.
*/

static int	word_count(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

/*
**	Returns a substring from str, with
** 	char zero at index start and finishing
**	the copy at index finish.
*/

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(((finish - start) * sizeof(char)) + 1);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

/*
**	Split a string into one or more substrings,
**	returning an array of substrings. The split
**	is made according the separator c.
*/

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	if (!(split = malloc((word_count(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
