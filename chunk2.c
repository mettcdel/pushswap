/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:05:21 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:05:22 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stx **b, t_cnt *cnt)
{
	int		pos;
	t_stx	*temp;
	int		count;

	temp = *b;
	count = cnt->b_cnt;
	pos = 0;
	while (count-- && temp != NULL)
	{
		if (temp->index == cnt->b_cnt - 1)
			return (pos);
		pos++;
		temp = temp->next;
	}
	return (0);
}

int	f_sqrt(int val)
{
	int	x;

	x = 1;
	while (x * x < val)
		x++;
	return (x);
}
