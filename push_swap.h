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
	int				num;
	int				idx;
	struct s_list	*next;
}	t_list;

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
int		ft_is_sorted(f_list *addrs);
int		ft_get_idx(f_list *addrs ,int num);
int		ft_idx_num_b(f_list *b_addrs, int num);
int		ft_idx_num_a(f_list *a_addrs, int num);
int		ft_cal_rotate_ab(f_list *a_addrs, f_list *b_addrs);
int		ft_cal_rarb_a(f_list *a_addrs, f_list *b_addrs, int num);
int		ft_cal_rrarb_a(f_list *a_addrs, f_list *b_addrs, int num);
int		ft_cal_rarrb_a(f_list *a_addrs, f_list *b_addrs, int num);
int		ft_cal_rrarrb_a(f_list *a_addrs, f_list *b_addrs, int num);
int		ft_cal_rotate_ba(f_list *a_addrs, f_list *b_addrs);
int		ft_cal_rarb_b(f_list *a_addrs, f_list *b_addrs, int num);
int		ft_cal_rrarb_b(f_list *a_addrs, f_list *b_addrs, int num);
int		ft_cal_rarrb_b(f_list *a_addrs, f_list *b_addrs, int num);
int		ft_cal_rrarrb_b(f_list *a_addrs, f_list *b_addrs, int num);
int		ft_go_rarb(f_list *a_addrs, f_list *b_addrs, int value, char flag);
int		ft_go_rarrb(f_list *a_addrs, f_list *b_addrs, int value, char flag);
int		ft_go_rrarb(f_list *a_addrs, f_list *b_addrs, int value, char flag);
int		ft_go_rrarrb(f_list *a_addrs, f_list *b_addrs, int value, char flag);

char	*ft_strjoin(char *str, char *c);

void	ft_counter(char *s, char c, int *counter);
void 	ft_set_a_b(int i, int *num, f_list *a_addrs, f_list *b_addrs);
void    ft_max_min(f_list *addrs);
void    ft_indxing(f_list *addrs);
void	ft_sa(f_list *a_addrs, int print);
void	ft_sb(f_list *b_addrs, int print);
void	ft_ss(f_list *a_addrs, f_list *b_addrs);
void    ft_pb(f_list *a_addrs, f_list *b_addrs);
void    ft_pa(f_list *a_addrs, f_list *b_addrs);
void    ft_ra(f_list *a_addrs, int print);
void    ft_rb(f_list *b_addrs, int print);
void    ft_rr(f_list *a_addrs, f_list *b_addrs);
void    ft_rra(f_list *a_addrs, int print);
void    ft_rrb(f_list *b_addrs, int print);
void    ft_rrr(f_list *a_addrs, f_list *b_addrs);
void    ft_sort_a(f_list *a_addrs, f_list *b_addrs);
void    ft_sort_b(f_list *a_addrs, f_list *b_addrs);
void    ft_sort_is_three(f_list *a_addrs);
void	ft_sort_final(f_list *a_addrs, f_list *b_addrs);
void    ft_sort_b_three(f_list *a_addrs, f_list *b_addrs);
void	ft_free_link(f_list *addrs);

void	ft_print_stack(f_list *addrs);
#endif
