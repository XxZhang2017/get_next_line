/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:26:10 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/25 11:55:35 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_node_data(t_list **t, char **helper)
{
    t_list	*tmp;
	char	*help_line;
    int     len;

    len = 0;
    if (!(*t))
		return (-1);
	while (*t && (*t)->content)
	{
		while (((*t)->content)[len])
		{
			if (((*t)->content)[len] == '\n')
			{
				copy_to_helper(helper, t, len);
				return (1);
			}
			len++;
		}
		help_line = *helper;
		(*helper) = ft_strjoin((*helper), (*t)->content);
		tmp = (*t);
		(*t) = (*t)->next;
		free(tmp->content);
		free(help_line);
		free(tmp);
	}
	return (0);
}

void	        copy_to_helper(char **helper, t_list **t, int len)
{
    char	*h_line;

	h_line = *helper;
	(*helper) = ft_strnjoin((*helper), (*t)->content, len + 1);
	free(h_line);
	h_line = (*t)->content;
	if (len + 1 < ft_strlen((*t)->content))
		(*t)->content = ft_strdup(&(h_line[len + 1]));
	else
		(*t) = (*t)->next;
	free(h_line);
}

int		concat_helper(ssize_t *regbyte, char **helper, char *buf, t_list **tp)
{
    int		trace;
	char	*help_line;

	trace = ft_search(buf);
	if (trace != -1)
	{
		help_line = *helper;
		*helper = ft_strnjoin(*helper, buf, trace + 1);
		free(help_line);
		if (trace + 1 < *regbyte)
			ft_add_to_tail(buf, trace + 1, tp);
		return (1);
	} 
	help_line = *helper;
	*helper = ft_strnjoin(*helper, buf, *regbyte);
	free(help_line);
	return (0);
}

int get_next_line(int fd, char **line)
{
    char    *helper;
    static  t_list  *head[4096] = {NULL};  //init list to NULL?
    ssize_t read_buf;
    int     reg;
    char    buf[BUFF_SIZE + 1];

    helper = ft_strnew(0);
    if ((reg = get_node_data(&head[fd], &helper)) == 1)
    { line_helper(line, helper);}
    while((read_buf = read(fd, buf, BUFF_SIZE)) != 0)
    {
        check(read_buf);
        buf[read_buf] = '\0';
		if ((reg = concat_helper(&read_buf, &helper, buf, &head[fd])) == 1)
		{	 line_helper(line, helper);}
    }
    if (!(*helper) && (!head[fd]))
        return (0);
    else
    {  
        helper = ft_strjoin(helper, buf);
        line_helper(line, helper);
    }
}
