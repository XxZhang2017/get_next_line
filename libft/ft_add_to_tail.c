/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_to_tail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:45:43 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/20 14:33:36 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_add_to_tail(char *b, int tc, t_list **t)
{
	char	*ch;

	if (t)
	{
		if (!b)
			ch = NULL;
		else
			ch = ft_strdup(&b[tc]);
		*t = ft_append(*t, ch);
	}
}
