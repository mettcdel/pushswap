/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:08:28 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:09:38 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		n--;
		i++;
	}
	return (0);
}

static void	already_have(int val, t_cnt *cnt, char **sep)
{
	if (val > 1)
	{
		if (val == cnt->op || cnt->op != 6)
			free_exit(NULL, sep, 1);
		cnt->op = val;
	}
	if (val <= 1)
	{
		if (val == cnt->bench)
			free_exit(NULL, sep, 1);
		cnt->bench = val;
	}
	cnt->flag_w++;
}

static void	detecting(char **sep, t_cnt *cnt)
{
	int	j;

	j = 0;
	while (sep[j] != NULL)
	{
		if (ft_strncmp(sep[j], "--bench", 8) == 0)
			already_have(1, cnt, sep);
		else if (ft_strncmp(sep[j], "--simple", 9) == 0)
			already_have(2, cnt, sep);
		else if (ft_strncmp(sep[j], "--medium", 9) == 0)
			already_have(3, cnt, sep);
		else if (ft_strncmp(sep[j], "--complex", 10) == 0)
			already_have(4, cnt, sep);
		else if (ft_strncmp(sep[j], "--adaptive", 11) == 0)
			already_have(5, cnt, sep);
		j++;
	}
}

void	detect_flag(char **argv, t_cnt *cnt)
{
	int		i;
	char	**sep;

	i = 1;
	while (argv[i] != NULL && i < 3)
	{
		sep = ft_split(argv[i], ' ');
		if (sep == NULL)
			free_exit(NULL, NULL, 1);
		if (sep[0] == NULL)
			free_exit(NULL, sep, 1);
		detecting(sep, cnt);
		free_split(sep);
		i++;
	}
}
