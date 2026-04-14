/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademirel <ademirel@student.42istanbul.com.tr> + +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:33:00 by ademirel          #+#    #+#             */
/*   Updated: 2026/04/08 03:37:24 by ademirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stx
{
	int				val;
	int				index;
	struct s_stx	*next;
}					t_stx;
typedef struct s_cnt
{
	float	dr;
	int		chunk_val;
	int		b_cnt;
	int		a_cnt;
	int		flag_w;
	int		op;
	int		bench;
	int		sa_cnt;
	int		sb_cnt;
	int		ss_cnt;
	int		pa_cnt;
	int		pb_cnt;
	int		ra_cnt;
	int		rb_cnt;
	int		rr_cnt;
	int		rra_cnt;
	int		rrb_cnt;
	int		rrr_cnt;
}			t_cnt;

long	ft_atol(t_stx **a, char **f_input, const char *nptr);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	ft_lstadd_back(t_stx **lst, t_stx *new);
t_stx	*ft_lstnew(int content);
void	sa(t_stx **a, t_cnt *cnt);
void	sb(t_stx **b, t_cnt *cnt);
void	ss(t_stx **stack_a, t_stx **stack_b, t_cnt *cnt);
void	pa(t_stx **b, t_stx **a, t_cnt *cnt);
void	pb(t_stx **a, t_stx **b, t_cnt *cnt);
void	ra(t_stx **a, t_cnt *cnt);
void	rb(t_stx **b, t_cnt *cnt);
void	rr(t_stx **stack_a, t_stx **stack_b, t_cnt *cnt);
void	rra(t_stx **a, t_cnt *cnt);
void	rrb(t_stx **b, t_cnt *cnt);
void	rrr(t_stx **a, t_stx **b, t_cnt *cnt);
void	ft_lstclear(t_stx **lst);
void	free_split(char **a);
void	free_exit(t_stx **a, char **f_input, int err);
void	detect_flag(char **argv, t_cnt *cnt);
void	ft_selection(t_stx **a, t_stx **b, t_cnt *cnt);
void	chosen_alg(t_stx **a, t_stx **b, t_cnt *cnt);
int		find_max(t_stx **b, t_cnt *cnt);
void	chunk_sort(t_stx **a, t_stx **b, t_cnt *cnt);
void	index_param(t_stx **a, t_cnt *cnt);
int		f_sqrt(int val);
void	radix_sort(t_stx **a, t_stx **b, t_cnt *cnt);
void	set_disorder(t_stx **a, t_cnt *cnt);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_bench(t_cnt *cnt);
int		total_move(t_cnt *stck_cnt);
void	sortto_2(t_stx **a, t_cnt *cnt);
void	sortto_3(t_stx **a, t_cnt *cnt);
void	sortto_5(t_stx **a, t_stx **b, t_cnt *cnt);
void	under_5(t_stx **a, t_stx **b, t_cnt *cnt);

#endif
