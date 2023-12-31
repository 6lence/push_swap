/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:52:41 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/17 12:36:09 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

//push up every element of B, first become last
void	ft_rb(t_stack **a, t_data *l)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (l->print == 0)
		ft_printf("rb\n");
}

//push up every element of A, first become last
void	ft_ra(t_stack **a, t_data *l)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (l->print == 0)
		ft_printf("ra\n");
}

//push up every element of A and B, first become last
void	ft_rr(t_stack **a, t_stack **b, t_data *l)
{
	l->print = 1;
	ft_ra(a, l);
	ft_rb(b, l);
	ft_printf("rr\n");
	l->print = 0;
}

//first element of A is push on B
void	ft_pb(t_stack **a, t_stack **b, t_data *l)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (l->print == 0)
		ft_printf("pb\n");
}

//first element of B is push on A
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
