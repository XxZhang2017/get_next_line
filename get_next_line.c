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

int		buf_line(ssize_t *regbyte, char **line, char *buf, t_list **tp)
{
	int		trace;
	char	*help_line;

	trace = ft_search(buf);
	if (trace != -1)
	{
		help_line = *line;
		*line = ft_strnjoin(*line, buf, trace);
		free(help_line);
		if (trace + 1 < *regbyte)
			ft_add_to_tail(buf, trace + 1, tp);
		return (1);
	}
	help_line = *line;
	*line = ft_strnjoin(*line, buf, *regbyte);
	free(help_line);
	return (0);
}

int		get_node_data_to_line(t_list **t, char **line)
{
	int	len;

	if (!(*t))
		return (-1);
	len = 0;
	*line = NULL;
	return (get_data_helper(t, line, len));
}

int		get_data_helper(t_list **t, char **line, int len)
{
	t_list	*tmp;
	char	*help_line;

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
		help_line = *line;
		(*line) = ft_strjoin((*line), (*t)->content);
		tmp = (*t);
		(*t) = (*t)->next;
		free(tmp->content);
		free(help_line);
		free(tmp);
	}
	return (0);
}

void	copy_content_line(char **line, t_list **t, int len)
{
	char	*h_line;

	h_line = *line;
	(*line) = ft_strnjoin((*line), (*t)->content, len);
	free(h_line);
	h_line = (*t)->content;
	if (len + 1 < ft_strlen((*t)->content))
		(*t)->content = ft_strdup(&(h_line[len + 1]));
	else
		(*t) = (*t)->next;
	free(h_line);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t			regbyte;
	int				reg[2];
	char			buf[BUFF_SIZE + 1];
	static t_list	*head[255] ={NULL};

	reg[1] = -1;
	if (fd < 0 || line == NULL)
		return (-1);
	buf[0] = '\0';
	if ((reg[0] = get_node_data_to_line(&head[fd], line)) == 1)
		return (1);
	if (reg[0] == -1 && *line)
		*line = NULL;
	while ((regbyte = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (regbyte == -1)
			return (-1);
		buf[regbyte] = '\0';
		if ((reg[1] = buf_line(&regbyte, line, buf, &head[fd])) == 1)
			return (1);
	}
	if (reg[1] == 0 || reg[0] == 0 ||
			((reg[0] = get_node_data_to_line(&head[fd], line)) == 1))
		return (1);
	return (0);
}
