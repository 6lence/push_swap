/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:48:15 by miguel            #+#    #+#             */
/*   Updated: 2023/09/04 15:35:55 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_lstpos(int x, t_stack **a)
{
	int	i;

	i = 0;
	while (x != (*a)->x)
	{
		*a = (*a)->next;
		i++;
	}
	return (i);
}