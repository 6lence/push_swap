/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:57:34 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/17 12:36:47 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_normal_algo(char **argv, t_stack **a, t_data *l)
{
	if (argc == 2)
		ft_init_str(argv[1], a, l);
	else if (argc > 2)
		ft_init_args(argv + 1, a, l);
}
