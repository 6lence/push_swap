/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:07:38 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/06 16:12:54 by miguel           ###   ########.fr       */
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
	if (l->size_a < 3 && (*a)->x > (*a)->next->x)
		ft_sa(a, l);
	else if (l->size_a == 3)
		ft_three(a, l);
	else if (l->size_a > 3)
		ft_sort_until_three(a, &b, l);
	ft_free_stack(&b);
}
