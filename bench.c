/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcodel <mcodel@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:59:43 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/28 13:25:14 by mcodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_cnt *cnt)
{
	float	percentage;
	int		integer_part;
	int		decimal_part;

	percentage = cnt->dr * 100.0f;
	integer_part = (int)percentage;
	decimal_part = (int)(percentage * 100.0f) % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(integer_part, 2);
	ft_putstr_fd(".", 2);
	if (decimal_part < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimal_part, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_algo(t_cnt *cnt)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (cnt->op == 2)
		ft_putstr_fd("Simple / O(n²)\n", 2);
	else if (cnt->op == 3)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (cnt->op == 4)
		ft_putstr_fd("Complex / O(nlogn)\n", 2);
	else if (cnt->op == 5 || cnt->op == 6)
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (cnt->dr < 0.2)
			ft_putstr_fd("O(n²)\n", 2);
		else if (cnt->dr < 0.5)
			ft_putstr_fd("O(n√n)\n", 2);
		else
			ft_putstr_fd("O(nlogn)\n", 2);
	}
}

static void	print_mvs1(t_cnt *cnt)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_move(cnt), 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(cnt->sa_cnt, 2);
	ft_putstr_fd(" | sb: ", 2);
	ft_putnbr_fd(cnt->sb_cnt, 2);
	ft_putstr_fd(" | ss: ", 2);
	ft_putnbr_fd(cnt->ss_cnt, 2);
	ft_putstr_fd(" | pa: ", 2);
	ft_putnbr_fd(cnt->pa_cnt, 2);
	ft_putstr_fd(" | pb: ", 2);
	ft_putnbr_fd(cnt->pb_cnt, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_mvs2(t_cnt *cnt)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(cnt->ra_cnt, 2);
	ft_putstr_fd(" | rb: ", 2);
	ft_putnbr_fd(cnt->rb_cnt, 2);
	ft_putstr_fd(" | rr: ", 2);
	ft_putnbr_fd(cnt->rr_cnt, 2);
	ft_putstr_fd(" | rra: ", 2);
	ft_putnbr_fd(cnt->rra_cnt, 2);
	ft_putstr_fd(" | rrb: ", 2);
	ft_putnbr_fd(cnt->rrb_cnt, 2);
	ft_putstr_fd(" | rrr: ", 2);
	ft_putnbr_fd(cnt->rrr_cnt, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_bench(t_cnt *cnt)
{
	if (!cnt)
		return ;
	print_disorder(cnt);
	print_algo(cnt);
	print_mvs1(cnt);
	print_mvs2(cnt);
}
