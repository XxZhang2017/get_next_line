/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:02:00 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/27 23:22:51 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BUFF_SIZE	100
# define CHECK(re) if (re == -1) return (-1)
# define LINE_HELPER(li, he) *li = ft_strdup(he);free(he); return (1)
# define FREE_THREE(a, b, c) free(a); free(b); free(c)
# define NULL_RETURN(a) if (!a) return (-1)
# define MOVE_L_PTR(tmp, a, b) tmp = a; a = b

int		get_node_data(t_list **t, char **helper);
int		get_next_line(const int fd, char **line);
int		concat_helper(ssize_t *regbyte, char **line, char *buf, t_list **tp);
int		get_data_helper(t_list **t, char **helper, int len);
void	copy_to_helper(char **line, t_list **t, int len);
int		wrapper(char **hp_line, t_list **head, char *buf, int fd);
#endif
