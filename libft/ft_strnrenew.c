/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrenew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:30:06 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/28 19:37:06 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnrenew(char *a, char *b, int len)
{
	char	*tmp;

	if (a)
	{
		tmp = a;
		a = ft_strnjoin(a, b, len);
		free(tmp);
	}
	return (a);
}
