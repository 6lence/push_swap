/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:05:53 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/19 14:38:52 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_pos_sign(int pos, t_data *l, char c)
{
	if (c == 'b' && pos > l->size_b / 2)
	{
		l->sign_b = 1;
		pos = l->size_b - pos;
	}
	if (c == 'a' && pos > l->size_a / 2)
	{
		l->sign_a = 1;
		pos = l->size_a - pos;
	}
	return (pos);
}

void	ft_best_of(int pos_b1, int pos_b2, int pos_a, t_data *l)
{
	int	tmp_sign1;
	int	tmp_sign2;
	int	tot_b1;
	int	tot_b2;
	int	total;

	tmp_sign1 = 0;
	tmp_sign2 = 0;
	if (pos_b1 > l->size_b / 2)
	{
		pos_b1 = l->size_b - pos_b1;
		tmp_sign1 = 1;
	}
	if (pos_b2 > l->size_b / 2)
	{
		pos_b2 = l->size_b - pos_b2;
		tmp_sign2 = 1;
	}
	l->mirror = l->size_a - (l->size_a - pos_a);
	total = l->opt_b + l->opt_a;
	tot_b1 = pos_b1 + pos_a;
	tot_b2 = pos_b2 + l->mirror;
	if (((tot_b2 < tot_b1 && tot_b2 < total)
			|| (tot_b2 < total && 1 == tmp_sign2)))
	{
		l->sign_b = tmp_sign2;
		l->opt_a = l->mirror;
		l->opt_b = pos_b2;
		l->sign_a = 1;
	}
	else if ((tot_b1 < total || (tot_b1 < total && tmp_sign1 == 0)))
	{
		l->sign_b = tmp_sign1;
		l->opt_a = pos_a;
		l->opt_b = pos_b1;
		l->sign_a = 0;
	}
}

t_stack	*ft_mirror(t_stack *a, int i)
{
	t_stack	*tmp;
	int		k;
	int		len;

	if (!a)
		return (0);
	k = 0;
	tmp = a;
	len = ft_lstlen(a) - i;
	while (k < len - 1 && tmp)
	{
		k++;
		tmp = tmp->next;
	}
	return (tmp);
}

int	ft_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->x < tmp->next->x)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	ft_push_min(t_stack **a, t_stack **b, t_data *l)
{
	l->pos = ft_find(ft_lstmin(*a), *a);
	l->sign_a = 0;
	if (l->pos > l->size_a / 2)
	{
		l->pos = l->size_a - l->pos;
		l->sign_a = 1;
	}
	while (l->pos)
	{
		if (l->sign_a == 1)
			ft_rra(a, l);
		else
			ft_ra(a, l);
		l->pos--;
	}
	ft_pb(a, b, l);
}
