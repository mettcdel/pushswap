/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:14:54 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:17:04 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_isdigit(const char *str, t_stx **a, char **f_input)
{
	int	i;

	if (str == NULL)
		free_exit(a, f_input, 1);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		free_exit(a, f_input, 1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			free_exit(a, f_input, 1);
		i++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ln;

	ln = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (ln);
	if (size > ln)
		size = ln + 1;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ln);
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

static void	is_printed(t_stx **a, char **f_input, int new)
{
	t_stx	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->val == new)
			free_exit(a, f_input, 1);
		tmp = tmp->next;
	}
}

long	ft_atol(t_stx **a, char **f_input, const char *nptr)
{
	int		i;
	int		sgn;
	long	rst;

	i = 0;
	sgn = 1;
	rst = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sgn = -sgn;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		rst = (rst * 10) + (nptr[i++] - '0');
		if ((sgn == 1 && rst > INT_MAX)
			|| (sgn == -1 && rst > (long)INT_MAX + 1))
			free_exit(a, f_input, 1);
	}
	ft_isdigit(nptr, a, f_input);
	is_printed(a, f_input, rst * sgn);
	return (rst * sgn);
}
