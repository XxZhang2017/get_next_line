/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:38:39 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/16 22:44:18 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(char *c)
{
	char	*a;
	int		count;

	count = 0;
	if (!c)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(c) + 1));
	while (*c)
	{
		a[count] = *c;
		count++;
		c++;
	}
	a[count] = '\0';
	return (a);
}
