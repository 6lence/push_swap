/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:15:59 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/05 11:06:32 by mescobar         ###   ########.fr       */
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

void	ft_push_back(t_stack **a, t_stack **b, t_data *l)
{
	
}
