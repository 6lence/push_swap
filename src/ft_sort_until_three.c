/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:40:23 by miguel            #+#    #+#             */
/*   Updated: 2023/09/20 14:55:44 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

//search the optimal position of A in B
int	ft_opt(t_stack *a, t_stack *b, t_data *l)
{
	t_stack	*tp_a;
	t_stack	*tp_b;

	tp_a = a;
	tp_b = b;
	l->max_b = ft_lstmax(tp_b);
	l->min_b = ft_lstmin(tp_b);
	if (tp_a->x < l->min_b || tp_a->x > l->max_b)
		return (ft_lstpos(l->max_b, b));
	if (tp_a->x > tp_b->x && tp_a->x < ft_lstlast(tp_b)->x
		&& (tp_b->x != l->min_b || tp_b->x != l->max_b)
		&& (ft_lstlast(tp_b)->x != l->min_b || ft_lstlast(tp_b)->x != l->max_b))
		return (0);
	return (ft_opt_utils(tp_a, tp_b, l));
}

//search the optimal element on A to put in B
static void	ft_elem(t_stack **a, t_stack **b, t_data *l)
{
	t_stack	*tmp;

	tmp = *a;
	l->pos = 0;
	l->sign_b = 0;
	l->opt_b = ft_opt(tmp, *b, l);
	if (l->opt_b > l->size_b / 2)
	{
		l->opt_b = l->size_b - l->opt_b;
		l->sign_b = 1;
	}
	l->pos = 1;
	tmp = tmp->next;
	while (tmp->next && l->pos < l->opt_b + l->opt_a)
	{
		ft_best_of(ft_opt(tmp, *b, l),
			ft_opt(ft_mirror(tmp, l->pos - 1), *b, l), l->pos, l);
		tmp = tmp->next;
		l->pos++;
	}
}

//push the optimal element from A to b
static void	ft_push(t_stack **a, t_stack **b, t_data *l)
{
	ft_move_in_a(a, b, l);
	ft_move_in_b(b, l);
	l->print = 0;
	ft_pb(a, b, l);
}

//rotate the two elements of b in case 1st < 2nd
static void	ft_2b(t_stack **b, t_data *l)
{
	if ((*b)->x < (*b)->next->x)
	{
		l->print = 0;
		ft_sb(b, l);
	}
	l->print = 1;
}

void	ft_sort_until_three(t_stack **a, t_stack **b, t_data *l)
{
	ft_pb(a, b, l);
	ft_pb(a, b, l);
	ft_2b(b, l);
	l->six_percent = (9 * ft_lstlen(*a) / 100);
	while (ft_lstlen(*a) > l->six_percent)
	{
		l->size_a = ft_lstlen(*a);
		l->size_b = ft_lstlen(*b);
		ft_elem(a, b, l);
		ft_push(a, b, l);
	}
	ft_max_first(b, l);
	while (ft_lstlen(*a) > 3)
	{
		l->size_a = ft_lstlen(*a);
		ft_push_min(a, b, l);
	}
	if (ft_lstlen(*a) == 3)
		ft_three(a, l);
	ft_push_back(a, b, l);
	while ((*a)->x != ft_lstmin(*a))
		ft_rra(a, l);
}
