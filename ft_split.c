/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:17:25 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:17:26 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*free_er(char **a, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (0);
}

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j + 1);
}

static char	**ft_farea(char **a, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	wcnt;

	i = 0;
	j = 0;
	wcnt = ft_words(s, c);
	while (s[i] == c)
		i++;
	while (j < wcnt)
	{
		k = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		a[j] = malloc(i - k + 1);
		if (a[j] == 0)
			return ((char **)free_er(a, j));
		ft_strlcpy(a[j], &s[k], i - k + 1);
		while (s[i] == c && s[i] != '\0')
			i++;
		j++;
	}
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	size_t	wordc;

	if (s == 0)
		return (0);
	wordc = ft_words(s, c);
	a = malloc(sizeof(char *) * (wordc + 1));
	if (a == 0)
		return (0);
	a[wordc] = 0;
	if (ft_farea(a, s, c) == 0)
		return (0);
	return (a);
}
