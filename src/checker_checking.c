/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:35:30 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/21 15:31:21 by mescobar         ###   ########.fr       */
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

void	ft_instruct(char *buf, t_stack **a, t_stack **b)
{
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'a' && buf[3] == '\n')
		ft_rra_checker(a);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'b' && buf[3] == '\n')
		ft_rra_checker(b);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'r' && buf[3] == '\n')
		ft_rrr_checker(a, b);
	else if (buf[0] == 'r' && buf[1] == 'a' && buf[2] == '\n')
		ft_ra_checker(a);
	else if (buf[0] == 'r' && buf[1] == 'b' && buf[2] == '\n')
		ft_ra_checker(b);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == '\n')
		ft_rr_checker(a, b);
	else if (buf[0] == 's' && buf[1] == 'a' && buf[2] == '\n')
		ft_sa_checker(a);
	else if (buf[0] == 's' && buf[1] == 'b' && buf[2] == '\n')
		ft_sa_checker(b);
	else if (buf[0] == 'p' && buf[1] == 'a' && buf[2] == '\n')
		ft_pa_checker(a, b);
	else if (buf[0] == 'p' && buf[1] == 'b' && buf[2] == '\n')
		ft_pa_checker(b, a);
	else
		ft_error_checker();
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

void	ft_sort(t_stack **a, t_stack **b)
{
	char	*buff;
	char	*tmp;
	int		cont;

	cont = 0;
	buff = ft_calloc(2, 1);
	tmp = ft_calloc(1, 1);
	*b = NULL;
	while (read(0, buff, 1))
	{
		tmp = ft_strjoin(tmp, &buff[0]);
		if (tmp[ft_strlen(tmp) - 1] == '\n')
		{
			ft_instruct(&tmp[cont], a, b);
			cont = ft_strlen(tmp);
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
