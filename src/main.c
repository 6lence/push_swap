/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:12:08 by miguel            #+#    #+#             */
/*   Updated: 2023/08/30 15:49:04 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_add_back(char *nb, t_stack **a)
{
	t_stack	*new;
	t_stack	*tmp;

	new = ft_calloc(1, sizeof(t_stack *));
	new->x = ft_atoi(nb);
	new->next = NULL;
	if (a == NULL)
	{
		*a = new;
		return ;
	}
	tmp = *a;
	ft_printf("%d\n", tmp->x);
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static void	ft_parsing_chain(char *chain, t_data *l)
{
	int		i;
	char	**tmp;

	ft_verif(chain, l);
	tmp = ft_split(chain, ' ');
	i = 0;
	while (tmp[i])
	{
		ft_add_back(tmp[i], &l->s_a);
		i++;
	}
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

static void	ft_parsing(char **str, t_data *l)
{
	int	i;

	i = 1;
	while (str[i])
	{
		ft_verif(str[i], l);
		ft_add_back(str[i], &l->s_a);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*l;

	l = ft_calloc(1, sizeof(t_data));
	if (argc < 2)
		ft_error("Invalid number of arguments.", l);
	if (argc == 2)
		ft_parsing_chain(argv[1], l);
	else if (argc > 2)
		ft_parsing(argv, l);
	ft_lstprint(&l->s_a);
}
