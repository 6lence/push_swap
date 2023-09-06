/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:12:08 by miguel            #+#    #+#             */
/*   Updated: 2023/09/07 01:18:54 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_add_back(char *nb, t_stack **a, t_data *l)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error("Malloc error ", l);
	new->x = ft_atoi(nb);
	new->next = NULL;
	if (*a)
		(ft_lstlast(*a))->next = new;
	else
		*a = new;
}

static void	ft_init_str(char *argv, t_stack **a, t_data *l)
{
	int		i;

	l->args = ft_split(argv, ' ');
	ft_repeat_verif(l->args, l);
	*a = NULL;
	i = 0;
	while (l->args[i])
	{
		ft_verif(l->args[i], l);
		ft_add_back(l->args[i++], a, l);
	}
}

static void	ft_init_args(char **nb, t_stack **a, t_data *l)
{
	int	i;

	ft_repeat_verif(nb, l);
	*a = NULL;
	i = 0;
	while (nb[i])
	{
		ft_verif(nb[i], l);
		ft_add_back(nb[i++], a, l);
	}
}

static void	ft_init(t_data *l, t_stack **a)
{
	l->max_a = ft_lstmax(*a);
	l->min_a = ft_lstmin(*a);
	l->size_a = ft_lstlen(*a);
}

int	main(int argc, char **argv)
{
	t_data	*l;
	t_stack	*a;

	l = ft_calloc(1, sizeof(t_data));
	if (argc < 2)
		ft_error("Not enough arguments", l);
	if (argc == 2)
		ft_init_str(argv[1], &a, l);
	else if (argc > 2)
		ft_init_args(argv + 1, &a, l);
	ft_init(l, &a);
	ft_swap(l, &a);
	ft_free_all(l);
	ft_free_stack(&a);
	return (0);
}
