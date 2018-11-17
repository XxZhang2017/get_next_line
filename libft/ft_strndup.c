/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 21:39:03 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/16 22:31:23 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup(char *c, int n)
{
	int		count;
	char	*reg;
	int		i;

	if (!c)
		return (NULL);
	count = (ft_strlen(c) > n) ? n : ft_strlen(c);
	reg = (char *)malloc(sizeof(char) * (count + 1));
	i = 0;
	while (i < count)
	{
		reg[i] = c[i];
		i++;
	}
	reg[i] = '\0';
	return (reg);
}
