/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils_3.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:06:03 by miguel            #+#    #+#             */
/*   Updated: 2023/09/20 11:35:36 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_move_in_a(t_stack **a, t_stack **b, t_data *l)
{
	while (l->opt_a > 0)
	{
		l->print = 0;
		if (l->sign_a == l->sign_b && l->sign_a == 1 && l->opt_b > 0)
		{
			ft_rrr(a, b, l);
			l->opt_b--;
		}
		else if (l->sign_a == l->sign_b && l->sign_a == 0 && l->opt_b > 0)
		{
			ft_rr(a, b, l);
			l->opt_b--;
		}
		else
		{
			if (l->sign_a == 1)
				ft_rra(a, l);
			else
				ft_ra(a, l);
		}
		l->opt_a--;
	}
}

void	ft_move_in_b(t_stack **b, t_data *l)
{
	while (l->opt_b > 0)
	{
		l->print = 0;
		if (l->sign_b == 1)
			ft_rrb(b, l);
		else
			ft_rb(b, l);
		l->opt_b--;
	}
}

int	ft_opt_utils(t_stack *tp_a, t_stack *tp_b, t_data *l)
{
	int	i;

	i = 0;
	while (tp_b->next)
	{
		if ((tp_b->x == l->min_b && tp_b->next->x == l->max_b)
			|| (tp_b->x == l->max_b && tp_b->next->x == l->min_b))
			i++;
		else if ((tp_a->x < tp_b->x && tp_a->x > tp_b->next->x))
			return (++i);
		else
			i++;
		tp_b = tp_b->next;
	}
	return (i);
}

int	ft_find_in_len(t_stack *b, int begining, int end)
{
	t_stack	*tmp;
	int		i;
	int		max;

	tmp = b;
	i = 0;
	while (i < begining && tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	max = 0;
	while (i < end && tmp->next)
	{
		if (max < tmp->x)
			max = tmp->x;
		tmp = tmp->next;
		i++;
	}
	return (max);
}

void	ft_affect_sign(int tmp_sign, int pos_a, int pos_b, t_data *l)
{
	l->sign_b = tmp_sign;
	l->opt_a = pos_a;
	l->opt_b = pos_b;
}
