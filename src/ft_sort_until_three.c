/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:40:23 by miguel            #+#    #+#             */
/*   Updated: 2023/09/14 00:45:43 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

//search the optimal position of A in B
static int	ft_opt(t_stack *a, t_stack *b, t_data *l)
{
	int		count;
	t_stack	*tmp_b;

	tmp_b = b;
	l->max_b = ft_lstmax(b);
	l->min_b = ft_lstmin(b);
	if (a->x > l->max_b || a->x < l->min_b)
		return (ft_lstpos(l->max_b, b));
	count = 0;
	while (!(a->x < tmp_b->x && a->x > tmp_b->x) && tmp_b->next)
	{
		count++;
		tmp_b = tmp_b->next;
	}
	return (count);
}

//search the optimal element on A to put in B
static void	ft_elem(t_stack **a, t_stack **b, t_data *l)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	l->opt_b = ft_best_of(ft_opt(tmp, *b, l),
			ft_opt(ft_mirror(tmp, 0), *b, l), l, 0);
	i = 1;
	while (tmp->next && i < l->opt_b)
	{
		l->opt_b = ft_best_of(ft_opt(tmp, *b, l),
				ft_opt(ft_mirror(tmp, 0), *b, l), l, i);
		i++;
		tmp = tmp->next;
	}
}

//push the optimal element from A to b
static void	ft_push(t_stack **a, t_stack **b, t_data *l)
{
	l->size_b = ft_lstlen(*b);
	l->size_a = ft_lstlen(*a);
	l->sign_b = ft_sign(l->opt_b, l->size_b);
	if (l->sign_b == 1)
	{
		l->opt_b = l->size_b - l->opt_b;
		if (l->opt_b < l->size_b / 2)
			l->sign_b = 0;
	}
	if (l->opt_a > l->size_a / 2)
	{
		l->opt_a = l->size_a - l->opt_a;
		if (l->opt_a < l->size_a / 2)
			l->sign_a = 0;
	}
	ft_printf("position A: %d, position B: %d\n", l->opt_a, l->opt_b);
	ft_printf("size A: %d, size B: %d\n", l->size_a, l->size_b);
	ft_printf("signe A: %d,  signe B: %d\n", l->sign_a, l->sign_b);
	while (l->opt_a > 0)
	{
		l->print = 0;
		if (l->sign_a == l->sign_b && l->sign_a == 1 && l->opt_b > 0)
		{
			ft_rrr(a, b, l);
			l->opt_b--;
		}
		else if (l->sign_a == l->sign_b && l->sign_a == 0 && l->opt_b > 0)
		{
			ft_rr(a, b, l);
			l->opt_b--;
		}
		else
		{
			if (l->sign_a == 1)
				ft_rra(a, l);
			else
				ft_ra(a, l);
		}
		l->opt_a--;
	}
	while (l->opt_b > 0)
	{
		l->print = 0;
		if (l->sign_b == 1)
			ft_rrb(b, l);
		else
			ft_rb(b, l);
		l->opt_b--;
	}
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
	while (ft_lstlen(*a) > 3)
	{
		ft_elem(a, b, l);
		ft_push(a, b, l);
	}
	if (ft_lstlen(*a) == 3)
		ft_three(a, l);
	else if ((*a)->x > (*a)->next->x && ft_lstlen(*a) == 2)
		ft_sa(a, l);
	ft_max_first(b, l);
	ft_push_back(a, b, l);
}
