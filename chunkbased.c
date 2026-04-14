/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkbased.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:06:41 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:06:57 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_index(int *stmp, t_stx **a, t_cnt *cnt)
{
	int		i;
	t_stx	*temp;
	int		j;

	i = 0;
	while (i < cnt->a_cnt)
	{
		temp = *a;
		j = 0;
		while (j < cnt->a_cnt)
		{
			if (stmp[i] == temp->val)
				temp->index = i;
			j++;
			temp = temp->next;
		}
		i++;
	}
}

static void	bubble_index(int *stmp, t_cnt *cnt)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < cnt->a_cnt - 1)
	{
		j = 0;
		while (j < cnt->a_cnt - 1)
		{
			if (stmp[j] > stmp[j + 1])
			{
				temp = stmp[j + 1];
				stmp[j + 1] = stmp[j];
				stmp[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_param(t_stx **a, t_cnt *cnt)
{
	t_stx	*temp;
	int		*stmp;
	int		i;

	stmp = (int *)malloc(cnt->a_cnt * sizeof(int));
	if (stmp == NULL)
		free_exit(a, NULL, 1);
	i = 0;
	temp = *a;
	while (temp)
	{
		stmp[i] = temp->val;
		temp = temp->next;
		i++;
	}
	bubble_index(stmp, cnt);
	insert_index(stmp, a, cnt);
	free(stmp);
}

static void	chunk_end(t_stx **a, t_stx **b, t_cnt *cnt)
{
	int		pos;
	int		pos2;

	while (cnt->b_cnt > 0)
	{
		pos = find_max(b, cnt);
		pos2 = cnt->b_cnt - pos;
		if (pos <= cnt->b_cnt / 2)
		{
			while (pos--)
				rb(b, cnt);
		}
		else
		{
			while (pos2--)
				rrb(b, cnt);
		}
		pa(b, a, cnt);
	}
}

void	chunk_sort(t_stx **a, t_stx **b, t_cnt *cnt)
{
	t_stx	*temp;
	int		range;

	if (cnt->a_cnt <= 5)
		under_5(a, b, cnt);
	else
	{
		index_param(a, cnt);
		range = f_sqrt(cnt->a_cnt);
		while (cnt->a_cnt > 0)
		{
			temp = *a;
			if (temp->index < cnt->b_cnt)
				pb(a, b, cnt);
			else if (temp->index < cnt->b_cnt + range)
			{
				pb(a, b, cnt);
				rb(b, cnt);
			}
			else
				ra(a, cnt);
		}
		chunk_end(a, b, cnt);
	}
}
