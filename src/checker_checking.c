/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:35:30 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/21 11:36:45 by mescobar         ###   ########.fr       */
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
	else
		ft_error_checker();
}

void	ft_sort(t_stack **a, t_stack **b)
{
	char	*buff;
	char	*tmp;

	buff = ft_calloc(2, 1);
	tmp = ft_calloc(1, 1);
	while (read(0, buff, 1))
	{
		ft_strlcat(tmp, buff, 1);
		if (tmp[ft_strlen(tmp) - 1] == '\n')
		{
			ft_instruct(buff, a, b);
			ft_printf("%s\n", tmp);
			ft_free(buff, tmp);
		}
	}
	ft_free(buff, tmp);
}

int	ft_sorted(t_stack **a)
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
