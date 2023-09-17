/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:48:15 by miguel            #+#    #+#             */
/*   Updated: 2023/09/17 12:36:29 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_lstpos(int x, t_stack *a)
{
	int		i;
	t_stack	*tmp;

	if (!a)
		return (0);
	i = 0;
	tmp = a;
	while (x != tmp->x)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
