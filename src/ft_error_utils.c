/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:38:36 by miguel            #+#    #+#             */
/*   Updated: 2023/09/18 15:24:19 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (*a)
	{
		while (*a)
		{
			tmp = *a;
			*a = (*a)->next;
			tmp->next = NULL;
			free(tmp);
		}
	}
}

void	ft_free_all(t_data *l)
{
	int	i;

	if (l->args)
	{
		i = 0;
		while (l->args[i])
			free(l->args[i++]);
		free(l->args);
	}
	if (l)
		free(l);
}

void	ft_error(char *str, t_data *l)
{
	ft_free_all(l);
	perror(str);
	exit(EXIT_FAILURE);
}
