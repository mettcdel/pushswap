/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:30:47 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:31:08 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bit(t_cnt *cnt)
{
	int	index;
	int	max;

	max = 0;
	index = cnt->a_cnt - 1;
	while (index > 0)
	{
		index = index >> 1;
		max++;
	}
	return (max);
}

void	radix_sort(t_stx **a, t_stx **b, t_cnt *cnt)
{
	int	i;
	int	max;
	int	size;

	if (cnt->a_cnt <= 5)
		under_5(a, b, cnt);
	else
	{
		i = -1;
		index_param(a, cnt);
		max = max_bit(cnt);
		while (++i < max)
		{
			size = cnt->a_cnt;
			while (size--)
			{
				if ((*a)->index >> i & 1)
					ra(a, cnt);
				else
					pb(a, b, cnt);
			}
			while (cnt->b_cnt > 0)
				pa(b, a, cnt);
		}
	}
}
