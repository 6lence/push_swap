/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:38:36 by miguel            #+#    #+#             */
/*   Updated: 2023/09/03 17:27:01 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

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
