/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:03:27 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/03 18:50:39 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_lstlen(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_lstprint(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->x);
		tmp = tmp->next;
	}
}

t_stack	*ft_lstlast(t_stack *st)
{
	if (!st)
		return (NULL);
	while (st->next)
		st = st->next;
	return (st);
}

int	ft_lstmin(t_stack *a)
{
	int	ct;

	ct = a->x;
	while (a)
	{
		if (ct > a->x)
			ct = a->x;
		a = a->next;
	}
	return (ct);
}

int	ft_lstmax(t_stack *a)
{
	int	ct;

	ct = a->next;
	while (a)
	{
		if (ct < a->x)
			ct = a->x;
		a = a->next;
	}
	return (ct);
}
