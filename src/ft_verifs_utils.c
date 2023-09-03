/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:09:49 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/03 17:27:00 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

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
			if (ft_strsrch(str[i], str[j]) > 0)
				ft_error("The same number cannot exit multiple times", l);
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
		if (str[i] > '9' && str[i] < '0'
			&& str[i] != '-' && str[i] != '+')
			ft_error("Invalid arguments, try only numbers arguments.", l);
		if (i > 0 && (str[i] == '-' || str[i] == '+')
			&& str[i - 1] != ' ')
			ft_error("Invalid number in the chain.", l);
		i++;
	}
}
