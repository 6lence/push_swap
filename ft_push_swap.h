/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:20:53 by miguel            #+#    #+#             */
/*   Updated: 2023/08/29 15:06:11 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "src/ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int			x;
	t_stack		*next;
}				t_stack;

typedef struct s_data
{
	t_stack	*s_a;
	t_stack	*s_b;
}			t_data;

void	ft_error(char *str, t_data *l);

#endif