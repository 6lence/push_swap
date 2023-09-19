/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:35:30 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/18 16:58:06 by miguel           ###   ########.fr       */
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
	if (ft_strcmp(move, "pa\n"))
		ft_pa_checker(a, b);
	else if (ft_strcmp(move, "pb\n"))
		ft_pa_checker(b, a);
	else if (ft_strcmp(move, "sa\n"))
		ft_sa_checker(a);
	else if (ft_strcmp(move, "sb\n"))
		ft_sa_checker(b);
	else if (ft_strcmp(move, "ra\n"))
		ft_ra_checker(a);
	else if (ft_strcmp(move, "rra\n"))
		ft_rra_checker(a);
	if (ft_lstlen(*b) >= 2)
	{
		if (ft_strcmp(move, "rb\n"))
			ft_ra_checker(b);
		else if (ft_strcmp(move, "rrb\n"))
			ft_rra_checker(b);
		else if (ft_strcmp(move, "rr\n"))
			ft_rr_checker(a, b);
		else if (ft_strcmp(move, "rrr\n"))
			ft_rrr_checker(a, b);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	char	*buff;

	buff = get_next_line(0);
	ft_printf("%s\n", buff);
	while (buff)
	{
		ft_instruct(buff, a, b);
		free(buff);
		buff = get_next_line(0);
	}
	if (buff)
		free(buff);
}

int	sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->x < tmp->next->x)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
