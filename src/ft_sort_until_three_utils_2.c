/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:05:53 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/14 00:23:48 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_best_of(int a, int b, t_data *l, int pos)
{
	l->opt_a = pos;
	if (a >= b)
	{
		l->sign_a = 0;
		return (a);
	}
	else
		l->sign_a = 1;
	return (b);
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
