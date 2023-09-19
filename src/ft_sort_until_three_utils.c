/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:15:59 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/19 15:31:30 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_sign_stacks(t_stack **a, t_stack **b, t_data *l)
{
	l->sign_a = 0;
	l->sign_b = 0;
	if (l->opt_b > ft_lstlen(*b) / 2)
	{
		l->opt_b = ft_lstlen(*b) - l->opt_b;
		l->sign_b = 1;
	}
	if (l->opt_a > ft_lstlen(*a) / 2)
	{
		l->opt_a = ft_lstlen(*a) - l->opt_a;
		l->sign_a = 1;
	}
}

int	ft_find(int d, t_stack *a)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp->next)
	{
		if (tmp->x == d)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_max_first(t_stack **b, t_data *l)
{
	int	sign;
	int	i;

	l->max_b = ft_lstmax(*b);
	sign = 0;
	l->print = 0;
	i = ft_lstpos(l->max_b, *b);
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

void	ft_six_percent(t_stack **a, t_stack **b, t_data *l)
{
	int	i;

	i = 3;
	while ((*b)->x != ft_lstmax(*b))
	{
		while ((*b)->x < ft_lstlast(*a)->x && i > 0)
		{
			ft_rra(a, l);
			i--;
		}
		ft_pa(a, b, l);
		l->six_percent--;
	}
}

void	ft_push_back(t_stack **a, t_stack **b, t_data *l)
{
	int	i;

	i = l->six_percent;
	ft_six_percent(a, b, l);
	while ((*b))
	{
		while ((*b)->x < ft_lstlast(*a)->x && i-- > 0)
			ft_rra(a, l);
		ft_pa(a, b, l);
	}
}
