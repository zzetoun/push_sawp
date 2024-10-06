/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:46:54 by zzetoun           #+#    #+#             */
/*   Updated: 2024/09/05 11:46:55 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

int		dig(int c);
int		ft_strlen(char *s);
int		*ft_parse(char **argv);
int		*ft_assign(char *str, char c, int *sp_str);
int		ft_valid(char **argv, int i, int j, int flag);

char	*ft_strjoin(char *str, char *c);

void	ft_counter(char *s, char c, int *counter);

#endif
