/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:30:26 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:30:41 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	z;
	long	x;

	x = n;
	if (fd < 0)
		return ;
	if (x < 0)
	{
		x = -x;
		write(fd, "-", 1);
	}
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else if (x < 10)
	{
		z = (x % 10) + '0';
		write(fd, &z, 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (fd < 0)
		return ;
	if (s == 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
