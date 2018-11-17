/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 10:51:47 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/16 22:33:32 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*append_node(t_list *t, char *buf)
{
	t_list	*tmp;

	tmp = get_last_node(t);
	if (tmp)
	{
		tmp->next = (t_list *)malloc(sizeof(t_list));
		tmp->next->content = buf;
		tmp->next->next = NULL;
	}
	else
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->content = buf;
		tmp->next = NULL;
		t = tmp;
	}
	return (t);
}
