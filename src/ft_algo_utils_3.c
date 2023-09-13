/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:29:12 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/14 00:00:56 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

//push down every element of B, last become first
void	ft_rrb(t_stack **a, t_data *l)
{
	t_stack	*tmp;
	int		i;

	if (!(*a) || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (l->print == 0)
		ft_printf("rrb\n");
}

//push down every element of A, last become first
void	ft_rra(t_stack **a, t_data *l)
{
	t_stack	*tmp;
	int		i;

	if (!(*a) || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (l->print == 0)
		ft_printf("rra\n");
}

//push down every element of A and B, first become last
void	ft_rrr(t_stack **a, t_stack **b, t_data *l)
{
	l->print = 1;
	ft_rra(a, l);
	ft_rrb(b, l);
	ft_printf("rrr\n");
	l->print = 0;
}
