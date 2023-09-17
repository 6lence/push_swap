/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:20:53 by miguel            #+#    #+#             */
/*   Updated: 2023/09/17 12:37:12 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../src/ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int					x;
	struct s_stack		*next;
}				t_stack;

typedef struct s_data
{
	t_stack	*first;
	t_stack	*push;
	int		print;
	int		size_a;
	int		size_b;
	int		min_a;
	int		max_a;
	int		min_b;
	int		max_b;
	int		sign_a;
	int		sign_b;
	int		opt_a;
	int		opt_b;
	int		mirror;
	int		pos;
	t_stack	*best;
	char	**args;
}			t_data;

int		ft_opt(t_stack *a, t_stack *b, t_data *l);
void	ft_reinit(t_stack *a, t_stack *b, t_stack *elem, t_data *l); 
void	ft_best_of(int pos_b1, int pos_b2, int pos_a, t_data *l);
t_stack	*ft_mirror(t_stack *a, int i);
int		ft__pos_sign(int len, t_data *l, char c);
int		ft_lstlen(t_stack *a);
void	ft_lstprint(t_stack **a);
void	ft_verif(char *str, t_data *l);
void	ft_error(char *str, t_data *l);
void	ft_repeat_verif(char **str, t_data *l);
void	ft_free_all(t_data *l);
t_stack	*ft_lstlast(t_stack *st);
int		ft_lstmax(t_stack *a);
int		ft_lstmin(t_stack *a);
int		ft_lstpos(int x, t_stack *a);
void	ft_sa(t_stack **a, t_data *l);
void	ft_sb(t_stack **a, t_data *l);
void	ft_ss(t_stack **a, t_stack **b, t_data *l);
void	ft_ra(t_stack **a, t_data *l);
void	ft_rb(t_stack **a, t_data *l);
void	ft_rr(t_stack **a, t_stack **b, t_data *l);
void	ft_rra(t_stack **a, t_data *l);
void	ft_rrb(t_stack **a, t_data *l);
void	ft_rrr(t_stack **a, t_stack **b, t_data *l);
void	ft_pa(t_stack **a, t_stack **b, t_data *l);
void	ft_pb(t_stack **a, t_stack **b, t_data *l);
void	ft_three(t_stack **a, t_data *l);
void	ft_see_b(t_stack **b, t_data *l);
int		ft_find_a(t_stack **a, t_data *l);
void	ft_swap(t_data *l, t_stack **a);
void	ft_sort_until_three(t_stack **a, t_stack **b, t_data *l);
void	ft_push_swap(t_data *l, t_stack **a);
void	ft_push_back(t_stack **a, t_stack **b, t_data *l);
void	ft_max_first(t_stack **b, t_data *l);
void	ft_move_in_both(t_stack **a, t_stack **b, t_data *l);
void	ft_free_stack(t_stack **a);

//checker:
void	ft_verif_checker(char *str);
void	ft_verif_args_checker(char **args);
void	ft_ra_checker(t_stack **a);
void	ft_rr_checker(t_stack **a, t_stack **b);
void	ft_rra_checker(t_stack **a);
void	ft_rrr_checker(t_stack **a, t_stack **b);
void	ft_sa_checker(t_stack **a);
void	ft_pa_checker(t_stack **a, t_stack **b);
void	ft_instruct(char *move, t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
int		sorted(t_stack **a);

#endif