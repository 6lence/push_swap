/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:15:59 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/06 11:45:44 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_find_a(t_stack **a, t_data *l)
{
	int	i;

	i = 0;
	while (*a != l->push)
	{
		*a = (*a)->next;
		i++;
	}
	l->size_a = ft_lstlen(a);
	l->sign = 0;
	if (i > l->size_a / 2)
	{
		l->sign = 1;
		i = l->size_a - i;
	}
}

static void	ft_sign_stacks(t_stack **a, t_stack **b, t_data *l)
{
	l->sign_a = 0;
	l->sign_b = 0;
	if (l->opt > ft_lstlen(b) / 2)
	{
		l->opt = ft_lstlen(b) - l->opt;
		l->sign_b = 1;
	}
	if (l->opt_in_a > ft_lstlen(a) / 2)
	{
		l->opt_in_a = ft_lstlen(a) - l->opt_in_a;
		l->sign_a = 1;
	}
}

void	ft_move_in_both(t_stack **a, t_stack **b, t_data *l)
{
	while (l->opt_in_a >= 0)
	{
		ft_sign_stacks(a, b, l);
		if (sign_a == 1 && sign_b == 1 && l->opt_in_a > 0)
		{
			ft_rrr(a, b, l);
			l->opt--;
		}	
		else if (sign_a == 0 && sign_b == 0 && l->opt_in_a > 0)
		{
			ft_rr(a, b, l);
			l->opt--;
		}
		else
		{
			if (l->sign_a == 0)
				ft_ra(a, l);
			else
				ft_rra(a, l);
		}
		l->opt_in_a--;
	}
}

void	ft_max_first(t_stack **b, t_data *l)
{
	int	sign;
	int	i;

	l->max_b = ft_lstmax(b);
	sign = 0;
	i = ft_lstpos(l->max_b, b);
	if (i > ft_lstlen(b) / 2)
	{
		sign = 1;
		i = ft_lstlen(b) - i;
	}
	while (i >= 0)
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
	
}
