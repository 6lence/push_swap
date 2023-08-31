/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:38:36 by miguel            #+#    #+#             */
/*   Updated: 2023/08/30 15:27:22 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_free_all(t_data *l)
{
	if (l)
		free(l);
}

void	ft_error(char *str, t_data *l)
{
	ft_free_all(l);
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_verif(char *str, t_data *l)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' && str[i] < '0'
			&& str[i] != '-' && str[i] != '+')
			ft_error("Invalid arguments, try only numbers arguments.", l);
		if (i > 0 && (str[i] == '-' || str[i] == '+')
			&& str[i - 1] != ' ')
			ft_error("Invalid number in the chain.", l);
		i++;
	}
}

int	ft_lstlen(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	while (tmp != 0)
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
