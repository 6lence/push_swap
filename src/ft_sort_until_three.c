/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_until_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:40:23 by miguel            #+#    #+#             */
/*   Updated: 2023/09/04 15:48:06 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_2b(t_stack **b, t_data *l)
{
	if ((*b)->x < (*b)->next->x)
	{
		l->print = 0;
		ft_sb(b, l);
	}
	l->print = 1;
}

static int	ft_opt(t_stack **a, t_stack **b)
{
	int	len;

	if ((*a)->x > ft_lstmax(b) || (*a)->x < ft_lstmin(b))
	{
		if (ft_lstpos(ft_lstmax(b), b) < ft_lstlen(b) / 2)
			return (ft_lstpos(ft_lstmax(b), b));
		else
			return (ft_lstlen(b) - ft_lstpos(ft_lstmax(b), b));
	}
	len = 0;
	while (!((*a)->x < (*b)->x && (*a)->x > (*b)->next->x))
	{
		len++;
		*b = (*b)->next;
	}
	return (len);
}

static void	ft_push(t_stack **a, t_data *l)
{
}

static void	ft_elem(t_stack **a, t_stack **b, t_data *l)
{
	int	i;
	int	opt;
	int	new_opt;

	opt = ft_opt(a);
	i = 0;
	while (i < opt)
	{
		new_opt = ft_opt(a);
		if (new_opt < opt)
		{
			opt = new_opt;
			l->push = *a;
		}
		(*a)->next;
		i++;
	}
}

void	ft_sort_until_three(t_stack **a, t_stack **b, t_data *l)
{
	int		i;
	int		opt;
	int		tmp;

	ft_pb(a, b, l);
	ft_pb(a, b, l);
	ft_2b(b);
	l->first = *a;
	while (ft_lstlen(a) > 3)
	{
		ft_elem(a, b, l);
		ft_push(a, l);
	}
}
