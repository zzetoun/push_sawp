/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:44:49 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/11 11:44:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sa(f_list *a_addrs, int print_ss)
{
    t_list  *a_list;

    a_list = a_addrs->head->next;
    a_addrs->head->next = a_addrs->head->next->next;
    a_list->next = a_addrs->head;
    a_addrs->head = a_list;
    if (print_ss != 1)
        write(1,"sa\n",3);
}

void    ft_sb(f_list *b_addrs, int print_ss)
{
    t_list  *b_list;

    b_list = b_addrs->head->next;
    b_addrs->head->next = b_addrs->head->next->next;
    b_list->next = b_addrs->head;
    b_addrs->head = b_list;
    if (print_ss != 1)
        write(1,"sb\n",3);
}

void    ft_ss(f_list *a_addrs, f_list *b_addrs)
{
    ft_sa(a_addrs, 1);
    ft_sb(b_addrs, 1);
    write(1,"ss\n", 3);
}
