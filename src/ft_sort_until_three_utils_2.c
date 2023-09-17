/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:05:53 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/17 12:36:35 by mescobar         ###   ########.fr       */
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
	int	tot_b1;
	int	tot_b2;
	int	total;

	if (pos_b1 > l->size_b || pos_b2 > l->size_b)
		l->sign_b = 1;
	if (pos_b1 > l->size_b / 2)
		pos_b1 = l->size_b - pos_b1;
	if (pos_b2 > l->size_b / 2)
		pos_b2 = l->size_b - pos_b2;
	total = l->opt_b + l->opt_a;
	tot_b1 = pos_b1 + pos_a;
	tot_b2 = pos_b2 + l->mirror;
	if ((tot_b2 < tot_b1 && tot_b2 < total))
	{
		l->opt_a = l->mirror;
		l->opt_b = pos_b2;
		l->sign_a = 1;
	}
	else if (tot_b1 < total)
	{
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

void	ft_reinit(t_stack *a, t_stack *b, t_stack *elem, t_data *l)
{
	l->size_a = ft_lstlen(a);
	l->size_b = ft_lstlen(b);
	l->sign_a = 0;
	l->sign_b = 0;
	l->opt_a = 0;
	l->mirror = l->size_a - (l->size_a - l->pos);
	l->opt_b = ft_opt(elem, b, l);
	if (l->opt_b > l->size_b / 2)
	{
		l->opt_b = l->size_b - 1;
		l->sign_b = 1;
	}
}
