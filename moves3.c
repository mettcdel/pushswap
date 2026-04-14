/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:28:17 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 04:18:05 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stx **a, t_cnt *cnt)
{
	t_stx	*before_last;
	t_stx	*last;

	if (*a != NULL && (*a)->next != NULL)
	{
		last = *a;
		before_last = *a;
		while (last->next != NULL)
			last = last->next;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last->next = *a;
		before_last->next = NULL;
		*a = last;
		cnt->rra_cnt++;
		if (cnt->bench == 0)
			write(1, "rra\n", 4);
	}
}

static void	rra_d(t_stx **a)
{
	t_stx	*before_last;
	t_stx	*last;

	if (*a != NULL && (*a)->next != NULL)
	{
		last = *a;
		before_last = *a;
		while (last->next != NULL)
			last = last->next;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last->next = *a;
		before_last->next = NULL;
		*a = last;
	}
}

void	rrb(t_stx **b, t_cnt *cnt)
{
	t_stx	*before_last;
	t_stx	*last;

	if (*b != NULL && (*b)->next != NULL)
	{
		last = *b;
		before_last = *b;
		while (last->next != NULL)
			last = last->next;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last->next = *b;
		before_last->next = NULL;
		*b = last;
		cnt->rrb_cnt++;
		if (cnt->bench == 0)
			write(1, "rrb\n", 4);
	}
}

static void	rrb_d(t_stx **b)
{
	t_stx	*before_last;
	t_stx	*last;

	if (*b != NULL && (*b)->next != NULL)
	{
		last = *b;
		before_last = *b;
		while (last->next != NULL)
			last = last->next;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last->next = *b;
		before_last->next = NULL;
		*b = last;
	}
}

void	rrr(t_stx **a, t_stx **b, t_cnt *cnt)
{
	rra_d(a);
	rrb_d(b);
	cnt->rrr_cnt++;
	if (cnt->bench == 0)
		write(1, "rrr\n", 4);
}
