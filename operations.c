/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:29:53 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:30:16 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chosen_alg(t_stx **a, t_stx **b, t_cnt *cnt)
{
	if (cnt->op == 2)
		ft_selection(a, b, cnt);
	else if (cnt->op == 3)
		chunk_sort(a, b, cnt);
	else if (cnt->op == 4)
		radix_sort(a, b, cnt);
	else if (cnt->op == 5 || cnt->op == 6)
	{
		if (cnt->dr < 0.2)
			ft_selection(a, b, cnt);
		else if (cnt->dr >= 0.2 && cnt->dr < 0.5)
			chunk_sort(a, b, cnt);
		else if (cnt->dr >= 0.5)
			radix_sort(a, b, cnt);
	}
	if (cnt->bench == 1)
		ft_bench(cnt);
}
