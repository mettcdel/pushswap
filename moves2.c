/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:23:21 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 04:17:25 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stx **a, t_cnt *cnt)
{
	t_stx	*last;
	t_stx	*tmp;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = *a;
		tmp = tmp->next;
		last = *a;
		while (last->next != NULL)
			last = last->next;
		last->next = *a;
		(*a)->next = NULL;
		*a = tmp;
		cnt->ra_cnt++;
		if (cnt->bench == 0)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stx **b, t_cnt *cnt)
{
	t_stx	*last;
	t_stx	*tmp;

	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = *b;
		tmp = tmp->next;
		last = *b;
		while (last->next != NULL)
			last = last->next;
		last->next = *b;
		(*b)->next = NULL;
		*b = tmp;
		cnt->rb_cnt++;
		if (cnt->bench == 0)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stx **stack_a, t_stx **stack_b, t_cnt *cnt)
{
	t_stx	*tmp;
	int		succes;

	succes = 0;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		tmp = *stack_a;
		tmp = tmp->next;
		ft_lstadd_back(stack_a, *stack_a);
		*stack_a = tmp;
		succes = 1;
	}
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		tmp = *stack_b;
		tmp = tmp->next;
		ft_lstadd_back(stack_b, *stack_b);
		*stack_b = tmp;
		succes = 1;
	}
	if (succes && cnt->bench == 0)
		write (1, "rr\n", 3);
	cnt->rr_cnt += succes;
}
