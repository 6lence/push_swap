/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:23:55 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/17 12:36:00 by mescobar         ###   ########.fr       */
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
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
			{
				perror("The same number cannot exist multiple times");
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
