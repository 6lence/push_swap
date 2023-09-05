/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:07:38 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/05 11:01:57 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

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

	b = ft_calloc(1, sizeof(t_stack));
	l->print = 0;
	if (l->size_a < 3)
		ft_sa(a, l);
	else if (l->size_a == 3)
		ft_three(a, l);
	else
		ft_sort_until_three(a, &b, l);
}
