/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:38:33 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/16 23:07:33 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char			*ft_strjoin(char *a, char *b);
int				ft_strlen(char *a);
char			*ft_strnjoin(char *a, char *b, int n);
char			*ft_strdup(char *c);
void			copy_to_tail(char *b, int trace, t_list **t);
t_list			*get_last_node(t_list *t);
t_list			*append_node(t_list *t, char *buf);
int				search_newline(char *a);
char			*ft_strndup(char *c, int n);
#endif
