/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:09:49 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/03 18:31:19 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_sb(t_stack **a, t_data *l)
{
	int		i;
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		ft_error("Void STACK: B ", l);
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (l->print == 0)
		ft_printf("sb\n");
}

void	ft_sa(t_stack **a, t_data *l)
{
	int		i;
	t_stack	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (l->print == 0)
		ft_printf("sa\n");
}

void	ft_ss(t_stack **a, t_stack **b, t_data *l)
{
	l->print = 1;
	ft_sa(*a, l);
	ft_sb(*b, l);
	ft_printf("sa\n");
}
