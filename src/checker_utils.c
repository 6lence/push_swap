/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:23:55 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/21 11:37:18 by mescobar         ###   ########.fr       */
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
	int	err;

	err = 0;
	i = 0;
	while (str[i])
	{
		if (ft_atol(str[i]) > INT_MAX || ft_atol(str[i]) < INT_MIN)
			err = 1;
		j = i + 1;
		while (str[j])
		{
			if (ft_atol(str[i]) == ft_atol(str[j]))
				err = 1;
			j++;
		}
		i++;
	}
	if (err == 1)
		ft_error_checker();
}

void	ft_verif_checker(char *str)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0')
			&& !(str[i] == '-' || str[i] == '+'))
			err = 1;
		if ((str[i] == '-' || str[i] == '+')
			&& str[i - 1] != ' ' && i > 0)
			err = 1;
		i++;
	}
	if (err == 1)
		ft_error_checker();
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

void	ft_free(char *buff, char *tmp)
{
	if (buff)
		free(buff);
	if (tmp)
		free(tmp);
}
