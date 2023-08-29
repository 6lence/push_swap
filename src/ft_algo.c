/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:43:33 by miguel            #+#    #+#             */
/*   Updated: 2023/08/29 16:09:37 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_sort_three(t_data **a)
{

}

void	ft_sort(t_stack *a, t_stack *b)
{
	int	len;

	len = ft_lstsize(a);
	if (len == 2)
		ft_sa(&a, 0);
	else if (len == 3)
		ft_sort_three(&a);
	else
		ft_sort_big(&a, &b);
}
