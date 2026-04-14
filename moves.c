/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:19:06 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 04:17:07 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stx **a, t_cnt *cnt)
{
	t_stx	*tmp;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = *a;
		tmp = tmp->next;
		(*a)->next = (*a)->next->next;
		tmp->next = *a;
		*a = tmp;
		cnt->sa_cnt++;
		if (cnt->bench == 0)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stx **b, t_cnt *cnt)
{
	t_stx	*tmp;

	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = *b;
		tmp = tmp->next;
		(*b)->next = (*b)->next->next;
		tmp->next = *b;
		*b = tmp;
		cnt->sb_cnt++;
		if (cnt->bench == 0)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stx **stack_a, t_stx **stack_b, t_cnt *cnt)
{
	t_stx	*tmp;
	int		succes;

	succes = 0;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		tmp = *stack_a;
		tmp = tmp->next;
		(*stack_a)->next = tmp->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		succes = 1;
	}
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		tmp = *stack_b;
		tmp = tmp->next;
		(*stack_b)->next = tmp->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		succes = 1;
	}
	if (succes && cnt->bench == 0)
		write(1, "ss\n", 3);
	cnt->ss_cnt += succes;
}

void	pa(t_stx **b, t_stx **a, t_cnt *cnt)
{
	t_stx	*temp;

	if (*b != NULL)
	{
		temp = *b;
		temp = temp->next;
		(*b)->next = *a;
		*a = *b;
		*b = temp;
		cnt->pa_cnt++;
		cnt->a_cnt++;
		cnt->b_cnt--;
		if (cnt->bench == 0)
			write(1, "pa\n", 3);
	}
}

void	pb(t_stx **a, t_stx **b, t_cnt *cnt)
{
	t_stx	*temp;

	if (*a != NULL)
	{
		temp = *a;
		temp = temp->next;
		(*a)->next = *b;
		*b = *a;
		*a = temp;
		cnt->pb_cnt++;
		cnt->a_cnt--;
		cnt->b_cnt++;
		if (cnt->bench == 0)
			write(1, "pb\n", 3);
	}
}
