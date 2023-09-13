/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:15:59 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/14 00:22:51 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_find_a(t_stack **a, t_data *l)
{
	int		i;
	t_stack	*tmp;

	if (!(*a))
		return (0);
	tmp = *a;
	i = 0;
	while (i != l->opt_a && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (l->sign_a == 1)
		return (ft_lstlen(*a) - i);
	return (i);
}

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

void	ft_move_in_both(t_stack **a, t_stack **b, t_data *l)
{
	(void)a;
	(void)b;
	(void)l;
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

void	ft_push_back(t_stack **a, t_stack **b, t_data *l)
{
	(void)a;
	(void)b;
	(void)l;
}
