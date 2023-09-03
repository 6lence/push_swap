/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:29:12 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/03 18:39:08 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_rrb(t_stack **a, t_data *l)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	(ft_lstlast(tmp))->next = NULL;
	if (l->print == 0)
		ft_printf("rrb\n");
}

void	ft_rra(t_stack **a, t_data *l)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	(ft_lstlast(tmp))->next = NULL;
	if (l->print == 0)
		ft_printf("rra\n");
}

void	ft_rrr(t_stack **a, t_stack **b, t_data *l)
{
	l->print = 1;
	ft_rra(a, l);
	ft_rrb(b, l);
	ft_printf("rrr\n");
}
