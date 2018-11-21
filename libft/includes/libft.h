/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:38:33 by xinzhang          #+#    #+#             */
/*   Updated: 2018/11/20 14:31:17 by xinzhang         ###   ########.fr       */
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
void			ft_add_to_tail(char *b, int trace, t_list **t);
t_list			*ft_get_last(t_list *t);
t_list			*ft_append(t_list *t, char *buf);
int				ft_search(char *a);
char			*ft_strndup(char *c, int n);
#endif
