/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcodel <mcodel@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:09:37 by mcodel            #+#    #+#             */
/*   Updated: 2026/04/27 21:12:59 by mcodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_position(t_stx **stack_b, t_cnt *info)
{
	int		position;
	t_stx	*current;
	int		target_index;

	if (!stack_b || !*stack_b)
		return (0);
	current = *stack_b;
	position = 0;
	target_index = info->b_cnt - 1;
	while (current != NULL)
	{
		if (current->index == target_index)
			return (position);
		position++;
		current = current->next;
	}
	return (0);
}
/ int calculate_sqrt(int number)
{
	int	root;

	if (number < 0)
		return (0);
	root = 1;
	while (root * root < number)
		root++;
	return (root);
}
