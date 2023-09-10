/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:07:38 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/10 22:49:21 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_sign(t_stack *a, t_data *l)
{
	t_stack	*tmp;
	int		ct;

	tmp = a;
	ct = 0;
	while (tmp->x != l->min_a)
	{
		ct++;
		tmp = tmp->next;
	}
	if (ct > ft_lstlen(a) / 2)
		ct = 1;
	else
		ct = 0;
	return (ct);
}

void	ft_three(t_stack **a, t_data *l)
{
	l->print = 0;
	l->max_a = ft_lstmax(*a);
	l->min_a = ft_lstmin(*a);
	if ((*a)->x == l->min_a)
	{
		if ((*a)->next->x == l->max_a)
		{
			ft_rra(a, l);
			ft_sa(a, l);
		}
	}
	else if ((*a)->x == l->max_a)
	{
		ft_ra(a, l);
		if ((*a)->x != l->min_a)
			ft_sa(a, l);
	}
	else
	{
		if ((*a)->next->x == l->min_a)
			ft_sa(a, l);
		else
			ft_rra(a, l);
	}
}

void	ft_swap(t_data *l, t_stack **a)
{
	t_stack	*b;

	b = NULL;
	l->print = 0;
	if (l->size_a < 3 && (*a)->x > (*a)->next->x)
		ft_sa(a, l);
	else if (l->size_a == 3)
		ft_three(a, l);
	else if (l->size_a > 3)
		ft_sort_until_three(a, &b, l);
}
