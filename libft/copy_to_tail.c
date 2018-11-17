/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_to_tail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:45:43 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/16 22:29:03 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	copy_to_tail(char *b, int trace, t_list **t)
{
	char	*ch;

	if (t)
	{
		if (!b)
			ch = NULL;
		else
			ch = ft_strdup(&b[trace]);
		*t = append_node(*t, ch);
	}
}
