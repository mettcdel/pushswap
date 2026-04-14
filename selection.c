/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:31:17 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 04:36:30 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stx *a)
{
	t_stx	*min;
	int		move;
	t_stx	*tmp;

	move = 0;
	min = a;
	tmp = a;
	while (tmp)
	{
		if (tmp->val < min->val)
			min = tmp;
		tmp = tmp->next;
	}
	while (a != min)
	{
		move++;
		a = a->next;
	}
	return (move);
}

void	sortto_2(t_stx **a, t_cnt *cnt)
{
	if ((*a)->val > (*a)->next->val)
		sa(a, cnt);
}

void	sortto_3(t_stx **a, t_cnt *cnt)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->val;
	second = (*a)->next->val;
	third = (*a)->next->next->val;
	if (first > second && first > third)
		ra(a, cnt);
	else if (second > first && second > third)
		rra(a, cnt);
	if ((*a)->val > (*a)->next->val)
		sa(a, cnt);
}

void	sortto_5(t_stx **a, t_stx **b, t_cnt *cnt)
{
	int	min;
	int	size;

	size = cnt->a_cnt;
	while (size > 3)
	{
		min = find_min(*a);
		if (min <= size / 2)
		{
			while (min--)
				ra(a, cnt);
		}
		else
		{
			while (min++ < size)
				rra(a, cnt);
		}
		pb(a, b, cnt);
		size--;
	}
	sortto_3(a, cnt);
	while (cnt->b_cnt > 0)
		pa(b, a, cnt);
}

void	ft_selection(t_stx **a, t_stx **b, t_cnt *cnt)
{
	int	move;

	if (cnt->a_cnt <= 5)
		under_5(a, b, cnt);
	else
	{
		while ((*a)->next)
		{
			move = find_min(*a);
			if ((cnt->a_cnt + 1) / 2 >= move)
			{
				while (move--)
					ra(a, cnt);
			}
			else
			{
				while (move++ < cnt->a_cnt)
					rra(a, cnt);
			}
			pb(a, b, cnt);
		}
		while (*b)
			pa(b, a, cnt);
	}
}
