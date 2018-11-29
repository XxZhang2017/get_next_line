/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:35:27 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/28 19:41:13 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*p;

	p = b;
	i = 0;
	while (len > 0)
		p[--len] = c;
	return (b);
}
