/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:09:49 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/21 14:18:50 by mescobar         ###   ########.fr       */
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
		if (ft_atol(str[i]) > INT_MAX || ft_atol(str[i]) < INT_MIN)
			ft_error("Error", l);
		j = i + 1;
		while (str[j])
		{
			if (ft_atol(str[i]) == ft_atol(str[j]))
				ft_error("Error", l);
			j++;
		}
		i++;
	}
}

void	ft_verif(char *str, t_data *l, t_stack **a)
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
			&& i > 0 && str[i - 1] != ' ')
			err = 1;
		i++;
	}
	if (err == 1)
	{
		ft_free_stack(a);
		ft_error("Error", l);
	}
}

void	ft_verif_str(char *argv, t_data *l)
{
	int		i;
	int		ct;

	if (!argv[0] || !argv)
	{
		ft_free_all(l);
		exit(EXIT_SUCCESS);
	}
	i = 0;
	ct = 0;
	while (argv[i])
	{
		if ((argv[i] > '9' || argv[i] < '0')
			&& (argv[0] != '-' || argv[0] != '+'))
			ct++;
		i++;
	}
	if (i == ct)
		ft_error("ERROR", l);
}
