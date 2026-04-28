/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:08:28 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/16 19:54:36 by ademirel         ###   ########.fr       */
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

static void	already_have(int val, t_cnt *cnt)
{
	if (val > 1)
	{
		if (val == cnt->op || cnt->op != 6)
			free_exit(NULL, NULL, 1);
		cnt->op = val;
	}
	if (val <= 1)
	{
		if (val == cnt->bench)
			free_exit(NULL, NULL, 1);
		cnt->bench = val;
	}
	cnt->flag_w++;
}

static void	detecting(char *sep, t_cnt *cnt)
{
	if (ft_strncmp(sep, "--bench", 8) == 0)
		already_have(1, cnt);
	else if (ft_strncmp(sep, "--simple", 9) == 0)
		already_have(2, cnt);
	else if (ft_strncmp(sep, "--medium", 9) == 0)
		already_have(3, cnt);
	else if (ft_strncmp(sep, "--complex", 10) == 0)
		already_have(4, cnt);
	else if (ft_strncmp(sep, "--adaptive", 11) == 0)
		already_have(5, cnt);
}

void	detect_flag(char **argv, t_cnt *cnt)
{
	int		i;

	i = 1;
	while (argv[i] != NULL && i < 3)
	{
		detecting(argv[i], cnt);
		i++;
	}
}
