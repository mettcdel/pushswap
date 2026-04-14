/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:57:53 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:02:33 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_disorder(t_stx **a, t_cnt *cnt)
{
	t_stx	*tmp1;
	t_stx	*tmp2;
	int		move;
	int		mistake;

	move = 0;
	mistake = 0;
	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->val > tmp2->val)
				mistake++;
			move++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	if (move != 0)
		cnt->dr = (float)mistake / (float)move;
}

int	total_move(t_cnt *stck_cnt)
{
	int	sum;

	sum = 0;
	sum += stck_cnt->sa_cnt;
	sum += stck_cnt->sb_cnt;
	sum += stck_cnt->ss_cnt;
	sum += stck_cnt->pa_cnt;
	sum += stck_cnt->pb_cnt;
	sum += stck_cnt->ra_cnt;
	sum += stck_cnt->rb_cnt;
	sum += stck_cnt->rr_cnt;
	sum += stck_cnt->rra_cnt;
	sum += stck_cnt->rrb_cnt;
	sum += stck_cnt->rrr_cnt;
	return (sum);
}

void	under_5(t_stx **a, t_stx **b, t_cnt *cnt)
{
	if (cnt->a_cnt == 2)
		sortto_2(a, cnt);
	else if (cnt->a_cnt == 3)
		sortto_3(a, cnt);
	else if (cnt->a_cnt <= 5)
		sortto_5(a, b, cnt);
}
