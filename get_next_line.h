/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:02:00 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/16 23:08:57 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BUFF_SIZE	4

int		get_node_data_to_line(t_list **t, char **line);
int		get_next_line(const int fd, char **line);
int		buf_line(ssize_t *regbyte, char **line, char *buf, t_list **tp);
int		get_data_helper(t_list **t, char **line, int len);
void	copy_content_line(char **line, t_list **t, int len);
#endif
