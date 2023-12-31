/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:09:49 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/18 14:46:24 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

//reverse 2 first elements from stack B
void	ft_sb(t_stack **a, t_data *l)
{
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

//reverse 2 first elements from stack A
void	ft_sa(t_stack **a, t_data *l)
{
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

//reverse 2 first elements from A and B at the same time
void	ft_ss(t_stack **a, t_stack **b, t_data *l)
{
	l->print = 1;
	ft_sa(a, l);
	ft_sb(b, l);
	ft_printf("sa\n");
}
