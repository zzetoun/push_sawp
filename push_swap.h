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
	int				content;
	int				rank;
	struct s_list	*next;
}					t_list;

typedef struct 
{
	t_list	*head;
	t_list	*tail;
	int		size;
} f_list;

int		dig(int c);
int		ft_strlen(char *s);
int		*ft_parse(char **argv);
int		*ft_assign(char *str, char c, int *sp_str);
int		ft_valid(char **argv, int i, int j, int flag);

char	*ft_strjoin(char *str, char *c);

void	ft_counter(char *s, char c, int *counter);
void 	ft_set_a_b(int *numbers, f_list *a_addrs, f_list *b_addrs);
void	ft_sa(f_list *a_addrs, int print_ss);
void	ft_sb(f_list *b_addrs, int print_ss);
void	ft_ss(f_list *a_addrs, f_list *b_addrs);
void    ft_pb(f_list *a_addrs, f_list *b_addrs);
void    ft_pa(f_list *a_addrs, f_list *b_addrs);
void    ft_ra(f_list *a_addrs, int print_rr);
void    ft_rb(f_list *b_addrs, int print_rr);
void	ft_free_link(f_list *list);

#endif
