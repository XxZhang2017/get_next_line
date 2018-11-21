/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 10:55:32 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/16 22:36:21 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char *a, char *b)
{
	char	*c;
	int		count;

	if (a == NULL && b == NULL)
		return (NULL);
	if (a == NULL && b)
		return (ft_strdup(b));
	if (a && b == NULL)
		return (ft_strdup(a));
	count = 0;
	c = (char *)malloc(sizeof(char) * (ft_strlen(b) + ft_strlen(a) + 1));
	while (*a)
		c[count++] = *a++;
	while (*b)
		c[count++] = *b++;
	c[count] = '\0';
	return (c);
}
