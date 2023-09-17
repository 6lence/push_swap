/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instruct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:45:45 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/17 12:37:20 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_ra_checker(t_stack **a)
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
}

void	ft_rr_checker(t_stack **a, t_stack **b)
{
	ft_ra_checker(a);
	ft_ra_checker(b);
}

void	ft_rra_checker(t_stack **a)
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
}

void	ft_rrr_checker(t_stack **a, t_stack **b)
{
	ft_rra_checker(a);
	ft_rra_checker(b);
}

void	ft_sa_checker(t_stack **a)
{
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}
