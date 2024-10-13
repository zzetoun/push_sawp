/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:46:54 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/12 11:46:55 by zzetoun          ###   ########.ae       */
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
	int				idx;
	struct s_list	*next;
}					t_list;

typedef struct 
{
	t_list	*head;
	t_list	*tail;
	int		max;
	int		min;
	int		size;
} f_list;

int		dig(int c);
int		ft_strlen(char *s);
int		*ft_parse(char **argv);
int		*ft_assign(char *str, char c, int *sp_str);
int		ft_valid(char **argv, int i, int j, int flag);
int		ft_get_idx(f_list *addrs ,int content);

char	*ft_strjoin(char *str, char *c);

void	ft_counter(char *s, char c, int *counter);
void 	ft_set_a_b(int i, int *num, f_list *a_addrs, f_list *b_addrs);
void    ft_max_min(f_list *addrs);
void    ft_indxing(f_list *addrs);
void	ft_sa(f_list *a_addrs, int print_ss);
void	ft_sb(f_list *b_addrs, int print_ss);
void	ft_ss(f_list *a_addrs, f_list *b_addrs);
void    ft_pb(f_list *a_addrs, f_list *b_addrs);
void    ft_pa(f_list *a_addrs, f_list *b_addrs);
void    ft_ra(f_list *a_addrs, int print_rr);
void    ft_rb(f_list *b_addrs, int print_rr);
void    ft_rr(f_list *a_addrs, f_list *b_addrs);
void    ft_rra(f_list *a_addrs, int print_rr);
void    ft_rrb(f_list *b_addrs, int print_rr);
void    ft_rrr(f_list *a_addrs, f_list *b_addrs);
void	ft_free_link(f_list *list);

#endif
