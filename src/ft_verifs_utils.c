/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:09:49 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/18 14:38:04 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

long int	ft_atol(const char *str)
{
	size_t	i;
	size_t	count;
	size_t	sign;

	i = 0;
	count = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		count = count * 10 + (str[i] - 48);
		i++;
	}
	return (count * sign);
}

void	ft_repeat_verif(char **str, t_data *l)
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
				ft_error("The same number cannot exit multiple times", l);
			if (ft_atol(str[i]) > INT_MAX || ft_atol(str[i]) < INT_MIN)
				ft_error("Try numbers between [INT_MIN, INT_MAX]", l);
			j++;
		}
		i++;
	}
}

void	ft_verif(char *str, t_data *l)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0')
			&& str[i] != '-' && str[i] != '+')
			ft_error("Invalid arguments, try only numbers arguments", l);
		if (i > 0 && (str[i] == '-' || str[i] == '+')
			&& str[i - 1] != ' ')
			ft_error("Invalid number in the chain.", l);
		i++;
	}
}
