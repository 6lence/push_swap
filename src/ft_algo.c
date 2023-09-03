/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:07:38 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/03 18:45:24 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_three(t_stack **a, t_data *l)
{
	if (ft_min(*a) == (*a)->x)
	{
		l->print = 0;
		ft_rra(a, l);
		ft_sa(a, l);
	}
}

void	ft_swap(t_data *l, t_stack **a)
{
	if (ft_lstsize(*a) < 3)
		ft_sa(a, l);
	else if (ft_lstsize(*a) == 3)
		ft_three(a, l);
	else
		ft_sort_until_three(l, a);
}
