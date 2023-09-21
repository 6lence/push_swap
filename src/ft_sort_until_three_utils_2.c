/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:05:53 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/20 11:35:37 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_sign_pos(int *tmp_sign, int *pos, t_data *l)
{
	if (*pos > l->size_b / 2)
	{
		*pos = l->size_b - *pos;
		*tmp_sign = 1;
	}
}

void	ft_best_of(int pos_b1, int pos_b2, int pos_a, t_data *l)
{
	int	tmp_sign1;
	int	tmp_sign2;
	int	tot_b1;
	int	tot_b2;

	tmp_sign1 = 0;
	tmp_sign2 = 0;
	ft_sign_pos(&tmp_sign1, &pos_b1, l);
	ft_sign_pos(&tmp_sign2, &pos_b2, l);
	l->mirror = l->size_a - (l->size_a - pos_a);
	l->total = l->opt_b + l->opt_a;
	tot_b1 = pos_b1 + pos_a;
	tot_b2 = pos_b2 + l->mirror;
	if (((tot_b2 < tot_b1 && tot_b2 < l->total)
			|| (tot_b2 < l->total && 1 == tmp_sign2)))
	{
		ft_affect_sign(tmp_sign2, l->mirror, pos_b2, l);
		l->sign_a = 1;
	}
	else if ((tot_b1 < l->total || (tot_b1 < l->total && tmp_sign1 == 0)))
	{
		ft_affect_sign(tmp_sign1, pos_a, pos_b1, l);
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
