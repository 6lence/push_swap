/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:35:30 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/17 12:36:01 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_stack	*ft_lstlast(t_stack *st)
{
	t_stack	*tmp;

	if (!st)
		return (NULL);
	tmp = st;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_pa_checker(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
}

void	ft_instruct(char *move, t_stack **a, t_stack **b)
{
	if (ft_strcmp(move, "pa"))
		ft_pa_checker(a, b);
	else if (ft_strcmp(move, "pb"))
		ft_pa_checker(b, a);
	else if (ft_strcmp(move, "sa"))
		ft_sa_checker(a);
	else if (ft_strcmp(move, "sb"))
		ft_sa_checker(b);
	else if (ft_strcmp(move, "ra"))
		ft_ra_checker(a);
	else if (ft_strcmp(move, "rb"))
		ft_ra_checker(b);
	else if (ft_strcmp(move, "rra"))
		ft_rra_checker(a);
	else if (ft_strcmp(move, "rrb"))
		ft_rra_checker(b);
	else if (ft_strcmp(move, "rr"))
		ft_rr_checker(a, b);
	else if (ft_strcmp(move, "rrr"))
		ft_rrr_checker(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	char	*buff;

	buff = get_next_line(1);
	while (buff)
	{
		ft_instruct(buff, a, b);
		buff = get_next_line(1);
	}
}

int	sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (!(tmp->x < tmp->next->x))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
