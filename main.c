/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:18:48 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/28 16:48:24 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	null_0(t_stx**a, t_stx **b, t_cnt *cnt)
{
	*a = NULL;
	*b = NULL;
	cnt->dr = 0;
	cnt->b_cnt = 0;
	cnt->a_cnt = 0;
	cnt->flag_w = 0;
	cnt->op = 6;
	cnt->bench = 0;
	cnt->sa_cnt = 0;
	cnt->sb_cnt = 0;
	cnt->ss_cnt = 0;
	cnt->pa_cnt = 0;
	cnt->pb_cnt = 0;
	cnt->ra_cnt = 0;
	cnt->rb_cnt = 0;
	cnt->rr_cnt = 0;
	cnt->rra_cnt = 0;
	cnt->rrb_cnt = 0;
	cnt->rrr_cnt = 0;
}

static void	printer(t_stx **a, t_cnt *cnt, char **argv)
{
	char	**f_input;
	int		i;
	int		j;

	i = 1;
	while (argv[i] != NULL)
	{
		f_input = ft_split(argv[i], ' ');
		if (!f_input || !f_input[0])
			free_exit(a, f_input, 1);
		j = 0;
		while (f_input[j] != NULL)
		{
			ft_lstadd_back(a, ft_lstnew((ft_atol(a, f_input, f_input[j]))));
			cnt->a_cnt++;
			j++;
		}
		free_split(f_input);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stx	*a;
	t_stx	*b;
	t_cnt	cnt;

	null_0(&a, &b, &cnt);
	detect_flag(argv, &cnt);
	argc = argc - (&cnt)->flag_w;
	argv = argv + (&cnt)->flag_w;
	if (argc < 2)
		exit(0);
	printer(&a, &cnt, argv);
	set_disorder(&a, &cnt);
	if ((&cnt)->dr == 0)
		free_exit(&a, NULL, 0);
	chosen_alg(&a, &b, &cnt);
	free_exit(&a, NULL, 0);
}
