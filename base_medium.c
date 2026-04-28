/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcodel <mcodel@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:07:23 by mcodel            #+#    #+#             */
/*   Updated: 2026/04/28 13:14:57 by mcodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_indices(int *sorted_array, t_stx **stack_a, t_cnt *info)
{
	int		i;
	int		j;
	t_stx	*curr;

	i = 0;
	while (i < info->a_cnt)
	{
		curr = *stack_a;
		j = 0;
		while (j < info->a_cnt)
		{
			if (sorted_array[i] == curr->val)
				curr->index = i;
			curr = curr->next;
			j++;
		}
		i++;
	}
}

static void	sort_temporary_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	normalize_stack(t_stx **stack_a, t_cnt *info)
{
	int		*tmp_arr;
	t_stx	*node;
	int		idx;

	tmp_arr = (int *)malloc(sizeof(int) * info->a_cnt);
	if (!tmp_arr)
		free_exit(stack_a, NULL, 1);
	node = *stack_a;
	idx = 0;
	while (node)
	{
		tmp_arr[idx++] = node->val;
		node = node->next;
	}
	sort_temporary_array(tmp_arr, info->a_cnt);
	apply_indices(tmp_arr, stack_a, info);
	free(tmp_arr);
}

static void	push_back_to_a(t_stx **stack_a, t_stx **stack_b, t_cnt *info)
{
	int	target_pos;
	int	reverse_steps;

	while (info->b_cnt > 0)
	{
		target_pos = find_max(stack_b, info);
		reverse_steps = info->b_cnt - target_pos;
		if (target_pos <= info->b_cnt / 2)
		{
			while (target_pos--)
				rb(stack_b, info);
		}
		else
		{
			while (reverse_steps--)
				rrb(stack_b, info);
		}
		pa(stack_b, stack_a, info);
	}
}

void	chunk_sort(t_stx **stack_a, t_stx **stack_b, t_cnt *info)
{
	int		offset;
	t_stx	*top;

	if (info->a_cnt <= 5)
	{
		under_5(stack_a, stack_b, info);
		return ;
	}
	normalize_stack(stack_a, info);
	offset = f_sqrt(info->a_cnt) * 1.4;
	while (info->a_cnt > 0)
	{
		top = *stack_a;
		if (top->index < info->b_cnt)
		{
			pb(stack_a, stack_b, info);
		}
		else if (top->index < info->b_cnt + offset)
		{
			pb(stack_a, stack_b, info);
			rb(stack_b, info);
		}
		else
			ra(stack_a, info);
	}
	push_back_to_a(stack_a, stack_b, info);
}
