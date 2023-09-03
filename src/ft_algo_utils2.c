/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:52:41 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/03 18:31:03 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_rb(t_stack **a, t_data *l)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	tmp->next = NULL;
	if (l->print == 0)
		ft_printf("rb\n");
}

void	ft_ra(t_stack **a, t_data *l)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	tmp->next = NULL;
	if (l->print == 0)
		ft_printf("ra\n");
}

void	ft_rr(t_stack **a, t_stack **b, t_data *l)
{
	l->print = 1;
	ft_ra(a, l);
	ft_rb(b, l);
	ft_printf("rr\n");
}

void	ft_pb(t_stack **a, t_stack **b, t_data *l)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
}

void	ft_pa(t_stack **a, t_stack **b, t_data *l)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (l->print == 0)
		ft_printf("pa\n");
}
