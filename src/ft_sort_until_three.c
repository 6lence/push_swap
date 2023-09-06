/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:40:23 by miguel            #+#    #+#             */
/*   Updated: 2023/09/07 01:33:41 by mescobar         ###   ########.fr       */
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
	int		len;
	t_stack	*tmp;

	l->min_b = ft_lstmin(*b);
	l->max_b = ft_lstmax(*b);
	if ((*a)->x > l->max_b || (*a)->x < l->min_b)
	{
		if (ft_lstpos(l->max_b, b) < ft_lstlen(*b) / 2)
			return (ft_lstpos(l->max_b, b));
		else
			return (ft_lstlen(*b) - ft_lstpos(l->max_b, b));
	}
	len = 0;
	tmp = *b;
	while (!((*a)->x < tmp->x && (*a)->x > tmp->next->x))
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

static void	ft_elem(t_stack **a, t_stack **b, t_data *l)
{
	int		i;
	int		new_opt;
	t_stack	*tmp;

	l->opt = ft_opt(a, b, l);
	i = 0;
	tmp = *a;
	while (i < l->opt || i < (ft_lstlen(*a) / 2))
	{
		new_opt = ft_opt(&tmp, b, l);
		if (new_opt < l->opt)
		{
			l->opt = new_opt;
			l->push = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	l->opt_in_a = i;
}

static void	ft_push(t_stack **a, t_stack **b, t_data *l)
{
	l->print = 1;
	ft_move_in_both(a, b, l);
	while (l->opt > 0)
	{
		if (l->sign_b)
			ft_rb(b, l);
		else
			ft_rrb(b, l);
		l->opt--;
	}
	ft_pb(a, b, l);
	ft_max_first(b, l);
}

void	ft_sort_until_three(t_stack **a, t_stack **b, t_data *l)
{
	ft_pb(a, b, l);
	ft_pb(a, b, l);
	ft_2b(b, l);
	l->first = *a;
	while (ft_lstlen(*a) > 3)
	{
		*a = l->first;
		ft_elem(a, b, l);
		ft_push(a, b, l);
	}
	ft_three(a, l);
	ft_lstprint(a);
	ft_push_back(a, b, l);
	l->min_a = ft_lstmin(*a);
	while ((*a)->x != l->min_a)
		ft_ra(a, l);
}
