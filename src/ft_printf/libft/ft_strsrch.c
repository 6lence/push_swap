/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsrch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:58:22 by mescobar          #+#    #+#             */
/*   Updated: 2023/09/06 15:19:53 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsrch(char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	printf("%s, %s\n", s1, s2);
	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s1[j] == s2[i])
		{
			i++;
			j++;
		}
		printf("%ld, %ld\n", j, ft_strlen(s1));
		if (j == ft_strlen(s1))
			return (1);
		else
			i -= j;
		i++;
	}
	return (0);
}
