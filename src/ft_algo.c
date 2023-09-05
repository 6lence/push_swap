/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:07:38 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/04 10:44:20 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_swap(t_data *l, t_stack **a)
{
	t_stack	*b;

	b = ft_calloc(1, sizeof(t_stack));
	if (l->size_a < 3)
		ft_sa(a, l);
	else if (l->size_a == 3)
		ft_three(a, l);
	else
		ft_sort_until_three(a, &b, l);
}
