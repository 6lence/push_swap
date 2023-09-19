/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:23:55 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/18 16:35:59 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

long int	ft_atol(const char *nptr)
{
	size_t	i;
	size_t	count;
	size_t	sign;

	i = 0;
	count = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		count = count * 10 + (nptr[i] - 48);
		i++;
	}
	return (count * sign);
}

void	ft_verif_args_checker(char **str)
{
	int	i;
	int	j;


	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atol(str[i]) == ft_atol(str[j]))
			{
				perror("The same number cannot exist multiple times");
				exit(EXIT_FAILURE);
			}
			if (ft_atol(str[i]) < INT_MIN || ft_atol(str[i]) > INT_MAX)
			{
				perror("Try numbers between [INT_MIN, INT_MAX]");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	ft_verif_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0')
			&& str[i] != '-' && str[i] != '+')
		{
			perror("Invalid arguments, try only numbers");
			exit(EXIT_FAILURE);
		}
		if (i > 0 && (str[i] == '-' || str[i] == '+')
			&& str[i - 1] != ' ')
		{
			perror("Invalid number in the chain");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

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
