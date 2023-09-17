/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:06:49 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/17 12:35:58 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_lstlen(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	ft_add_back_checker(char *nb, t_stack **a)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		exit(EXIT_FAILURE);
	new->x = ft_atoi(nb);
	new->next = NULL;
	if (*a)
		(ft_lstlast(*a))->next = new;
	else
		*a = new;
}

static void	ft_init_str_checker(char *argv, t_stack **a)
{
	int		i;
	char	**args;

	args = ft_split(argv, ' ');
	ft_verif_args_checker(args);
	*a = NULL;
	i = 0;
	while (args[i])
	{
		ft_verif_checker(args[i]);
		ft_add_back_checker(args[i], a);
	}
}

static void	ft_init_args_checker(char **argv, t_stack **a)
{
	int	i;

	ft_verif_args_checker(argv);
	*a = NULL;
	i = 0;
	while (argv[i])
	{
		ft_verif_checker(argv[i]);
		ft_add_back_checker(argv[i++], a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
		ft_init_str_checker(argv[1], &a);
	else if (argc > 2)
		ft_init_args_checker(argv + 1, &a);
	b = NULL;
	len = ft_lstlen(a);
	sort(&a, &b);
	if (b || ft_lstlen(a) != len || !sorted(&a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
