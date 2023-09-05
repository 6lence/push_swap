/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:15:59 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/05 16:52:01 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_see_b(t_stack **b, t_data *l)
{
	l->sign = 0;
	if (l->opt > ft_lstlen(b) / 2)
	{
		l->opt = ft_lstlen(b) - l->opt;
		l->sign = 1;
	}
}

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

void	ft_move_in_both(t_stack **a, t_stack **b, t_data *l)
{
	int	i;
	int	sign_a;
	int	sign_b;

	i = 0;
	sign_b = 0;
	sign_a = 0;
	if (l->opt > ft_lstlen(b) / 2)
	{
		l->opt = ft_lstlen(b) - l->opt;
		sign_b = 1;
	}
	if (l->opt_in_a > ft_lstlen(a) / 2)
	{
		l->opt_in_a = ft_lstlen(a) - l->opt_in_a;
		sign_a = 1;
	}
	while (i >= 0)
	{
		if (sign_a == sign_b && sign_a == 1 && (*a)->x > (*b)->x)
			ft_rrr(a, b, l);
		else if (sign_a == sign_b && sign_a == 0 && (*a)->x < (*b)->x)
			ft_rr(a, b, l);
		else
		{
			if (sign_a == 1)
				ft_rra(a, l);
			else
				ft_ra(a, l);
		}
	}
}
