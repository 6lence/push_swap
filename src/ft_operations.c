/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:48 by miguel            #+#    #+#             */
/*   Updated: 2023/08/29 16:12:49 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_sb(t_stack **b, int flag)
{
	t_stack	*tmp;

	if (!b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->next = tmp;
	if (flag == 0)
		ft_printf("sb\n");
}

void	ft_sa(t_stack **a, int flag)
{
	t_stack	*tmp;

	if (!a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->next = tmp;
	if (flag == 0)
		ft_printf("sa\n");
}