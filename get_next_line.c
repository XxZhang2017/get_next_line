/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:26:10 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/28 23:42:55 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		buf_line(ssize_t *regbyte, char **line, char *buf, t_list **tp)
{
	int	trace;

	trace = ft_search(buf);
	if (trace != -1)
	{
		*line = ft_strnrenew(*line, buf, trace);
		if (trace + 1 < *regbyte)
			ft_add_to_tail(buf, trace + 1, tp);
		return (1);
	}
	*line = ft_strnrenew(*line, buf, *regbyte);
	return (0);
}

int		get_node_data_to_line(t_list **t, char **line)
{
	int		len;
	t_list	*tmp;

	NULL_RETURN(t);
	len = 0;
	while (*t && (*t)->content)
	{
		while (((*t)->content)[len])
		{
			if (((*t)->content)[len] == '\n')
			{
				copy_content_line(line, t, len);
				return (1);
			}
			len++;
		}
		(*line) = ft_strrenew((*line), (*t)->content);
		tmp = (*t);
		(*t) = (*t)->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}

void	copy_content_line(char **line, t_list **t, int len)
{
	char	*h_line;
	t_list	*tmp;

	(*line) = ft_strnrenew((*line), (*t)->content, len);
	h_line = (*t)->content;
	if (len + 1 < ft_strlen((*t)->content))
		(*t)->content = ft_strdup(&(h_line[len + 1]));
	else
	{
		tmp = *t;
		(*t) = (*t)->next;
		free(tmp);
	}
	free(h_line);
}

int		wrapper(char **line, t_list **head, char *buf, int fd)
{
	if (!(**line) && (!(head[fd])))
	{
		FREE_POINTER(*line);
		return (0);
	}
	else
	{
		*line = ft_strrenew(*line, buf);
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	ssize_t			regbyte;
	int				reg[2];
	char			buf[BUFF_SIZE + 1];
	static t_list	*head[4096] = {NULL};

	reg[1] = -1;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_strnew(0);
	if ((reg[0] = get_node_data_to_line(&head[fd], line)) == 1)
		return (1);
	while ((regbyte = read(fd, buf, BUFF_SIZE)) != 0)
	{
		RETURN_NEG_ONE(regbyte);
		buf[regbyte] = '\0';
		if ((reg[1] = buf_line(&regbyte, line, buf, &head[fd])) == 1)
			return (1);
	}
	buf[0] = '\0';
	return (wrapper(line, &head[0], buf, fd));
}
