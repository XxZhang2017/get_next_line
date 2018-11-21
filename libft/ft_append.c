/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 10:51:47 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/20 14:33:12 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_append(t_list *t, char *n)
{
	t_list	*tmp;

	tmp = ft_get_last(t);
	if (tmp)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp->next->content = n;
		tmp->next->next = NULL;
	}
	else
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->content = n;
		tmp->next = NULL;
		t = tmp;
	}
	return (t);
}
