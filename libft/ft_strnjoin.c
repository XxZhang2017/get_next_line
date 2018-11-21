/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:49:10 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/16 22:32:45 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnjoin(char *a, char *b, int n)
{
	char	*c;
	int		count;
	int		j;

	count = 0;
	j = 0;
	if (a == NULL && b == NULL)
		return (NULL);
	if (a == NULL && b)
		return (ft_strndup(b, n));
	if (a && b == NULL)
		return (ft_strdup(a));
	c = (char *)malloc(sizeof(char) * (ft_strlen(a) + n + 1));
	while (*a)
		c[count++] = *a++;
	while (*b && j < n)
	{
		c[count] = *b;
		count++;
		b++;
		j++;
	}
	c[count] = '\0';
	return (c);
}
