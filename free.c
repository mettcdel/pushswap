/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:11:02 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:12:18 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stx **lst)
{
	t_stx	*a;

	if (lst == 0)
		return ;
	a = *lst;
	while (*lst)
	{
		a = a->next;
		free(*lst);
		*lst = a;
	}
}

void	free_split(char **a)
{
	size_t	i;

	i = 0;
	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
	free(a);
}

void	free_exit(t_stx **a, char **f_input, int err)
{
	int	i;

	i = 0;
	if (f_input != NULL)
	{
		while (f_input[i] != NULL)
		{
			free(f_input[i]);
			i++;
		}
		free(f_input);
	}
	if (a != NULL)
		ft_lstclear(a);
	if (err == 1)
		write(2, "Error\n", 6);
	exit(1);
}
