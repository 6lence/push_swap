/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:15:59 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/10 23:54:27 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_find_a(t_stack **a, t_data *l)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	while (tmp != l->push)
	{
		tmp = tmp->next;
		i++;
	}
	l->size_a = ft_lstlen(*a);
	l->sign_a = 0;
	if (i > l->size_a / 2)
	{
		l->sign_a = 1;
		i = l->size_a - i;
	}
}

static void	ft_sign_stacks(t_stack **a, t_stack **b, t_data *l)
{
	l->sign_a = 0;
	l->sign_b = 0;
	if (l->opt > ft_lstlen(*b) / 2)
	{
		l->opt = ft_lstlen(*b) - l->opt;
		l->sign_b = 1;
	}
	if (l->opt_in_a > ft_lstlen(*a) / 2)
	{
		l->opt_in_a = ft_lstlen(*a) - l->opt_in_a;
		l->sign_a = 1;
	}
}

void	ft_move_in_both(t_stack **a, t_stack **b, t_data *l)
{
	while (l->opt_in_a > 0)
	{
		ft_sign_stacks(a, b, l);
		if (l->sign_a == l->sign_b && l->sign_a == 1 && l->opt > 0)
		{
			ft_rrr(a, b, l);
			l->opt--;
		}
		else if (l->sign_a == l->sign_b && l->sign_a == 0 && l->opt > 0)
		{
			ft_rr(a, b, l);
			l->opt--;
		}
		else
		{
			l->print = 0;
			if (l->sign_a == 1)
				ft_rra(a, l);
			else if (l->sign_a == 0)
				ft_ra(a, l);
		}
		l->opt_in_a--;
	}
}

void	ft_max_first(t_stack **b, t_data *l)
{
	int	sign;
	int	i;

	l->max_b = ft_lstmax(*b);
	sign = 0;
	l->print = 0;
	i = ft_lstpos(l->max_b, b);
	if (i > ft_lstlen(*b) / 2)
	{
		sign = 1;
		i = ft_lstlen(*b) - i;
	}
	while (i > 0)
	{
		if (sign == 1)
			ft_rrb(b, l);
		else
			ft_rb(b, l);
		i--;
	}
}

void	ft_push_back(t_stack **a, t_stack **b, t_data *l)
{
	int	sign;

	l->print = 0;
	while (*b)
	{
		l->min_a = ft_lstmin(*a);
		l->max_a = ft_lstmax(*a);
		if ((*b)->x < (*a)->x && (*b)->x > ft_lstlast(*a)->x)
			ft_pa(a, b, l);
		else if ((*b)->x < l->min_a && (*a)->x == l->min_a)
			ft_pa(a, b, l);
		else if ((*b)->x > l->max_a && ft_lstlast(*a)->x == l->max_a)
			ft_pa(a, b, l);
		ft_ra(a, l);
	}
	l->min_a = ft_lstmin(*a);
	sign = ft_sign(*a, l);
	while ((*a)->x != l->min_a)
	{
		if (sign == 1)
			ft_rra(a, l);
		else
			ft_ra(a, l);
	}
}
