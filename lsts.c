/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:17:46 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:18:05 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stx	*ft_lstlast(t_stx *lst)
{
	t_stx	*a;

	if (lst == 0)
		return (0);
	a = lst;
	while (a->next)
		a = a->next;
	return (a);
}

t_stx	*ft_lstnew(int content)
{
	t_stx	*d;

	d = (t_stx *)malloc(sizeof(t_stx));
	if (d == 0)
		return (0);
	d->val = content;
	d->next = 0;
	return (d);
}

void	ft_lstadd_back(t_stx **lst, t_stx *new)
{
	t_stx	*a;

	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	a = ft_lstlast(*lst);
	a->next = new;
	new->next = 0;
}
