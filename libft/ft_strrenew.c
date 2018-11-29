/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:29:45 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/28 19:36:49 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrenew(char *a, char *b)
{
	char	*tmp;

	if (a)
	{
		tmp = a;
		a = ft_strjoin(a, b);
		free(tmp);
	}
	return (a);
}
