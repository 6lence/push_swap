/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:40:23 by miguel            #+#    #+#             */
/*   Updated: 2023/09/05 11:08:46 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_2b(t_stack **b, t_data *l)
{
	if ((*b)->x < (*b)->next->x)
	{
		l->print = 0;
		ft_sb(b, l);
	}
	l->print = 1;
}

static int	ft_opt(t_stack **a, t_stack **b, t_data *l)
{
	int	len;

	l->min_b = ft_lstmin(*b);
	l->max_b = ft_lstmax(*b);
	if ((*a)->x > l->max_b || (*a)->x < l->min_b)
	{
		if (ft_lstpos(l->max_b, b) < ft_lstlen(b) / 2)
			return (ft_lstpos(l->max_b, b));
		else
			return (ft_lstlen(b) - ft_lstpos(l->max_b, b));
	}
	len = 0;
	while (!((*a)->x < (*b)->x && (*a)->x > (*b)->next->x))
	{
		len++;
		*b = (*b)->next;
	}
	return (len);
}

static void	ft_push(t_stack **a, t_stack **b, t_data *l)
{
	int	i;

	l->print = 0;
	i = 0;
	while (i >= 0)
	{
		if (l->sign == 0)
			ft_ra(a, l);
		else if (l->sign == 1)
			ft_rra(a, l);
		i--;
	}
	ft_pb(a, b, l);
	ft_see_b(b, l);
	while (i < l->opt)
	{
		if (l->sign == 0)
			ft_rb(b, l);
		else if (l->sign == 1)
			ft_rrb(b, l);
		i++;
	}
}

static void	ft_elem(t_stack **a, t_stack **b, t_data *l)
{
	int	i;
	int	opt;
	int	new_opt;

	opt = ft_opt(a, b, l);
	i = 0;
	while (i < opt || i < (ft_lstlen(a) / 2))
	{
		new_opt = ft_opt(a, b, l);
		if (new_opt < opt)
		{
			opt = new_opt;
			l->push = *a;
		}
		*a = (*a)->next;
		i++;
	}
}

void	ft_sort_until_three(t_stack **a, t_stack **b, t_data *l)
{
	ft_pb(a, b, l);
	ft_pb(a, b, l);
	ft_2b(b, l);
	l->first = *a;
	while (ft_lstlen(a) > 3)
	{
		ft_elem(a, b, l);
		ft_push(a, b, l);
	}
	ft_three(a, l);
	ft_push_back(a, b, l);
}
