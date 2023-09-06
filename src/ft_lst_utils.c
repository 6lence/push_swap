/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:03:27 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/07 01:18:09 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_lstlen(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
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
	t_stack	*tmp;

	if (!st)
		return (NULL);
	tmp = st;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_lstmin(t_stack *a)
{
	int		ct;
	t_stack	*tmp;

	ct = a->x;
	tmp = a;
	while (tmp)
	{
		if (ct > tmp->x)
			ct = tmp->x;
		tmp = tmp->next;
	}
	return (ct);
}

int	ft_lstmax(t_stack *a)
{
	int		ct;
	t_stack	*tmp;

	ct = a->x;
	tmp = a;
	while (tmp)
	{
		if (ct < tmp->x)
			ct = tmp->x;
		tmp = tmp->next;
	}
	return (ct);
}
