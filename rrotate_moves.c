/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_moves.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:44:49 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/12 11:44:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rra(f_list *a_addrs, int print_rr)
{
    t_list  *a_list;

    a_list = a_addrs->head;
    while (a_list->next != a_addrs->tail)
        a_list = a_list->next;
    a_addrs->tail->next = a_addrs->head;
    a_addrs->head = a_addrs->tail;
    a_list->next = NULL;
    a_addrs->tail = a_list;
    if(print_rr != 1)
        write(1,"rra\n",4);
}

void    ft_rrb(f_list *b_addrs, int print_rr)
{
    t_list  *b_list;

    b_list = b_addrs->head;
    while (b_list->next != b_addrs->tail)
        b_list = b_list->next;
    b_addrs->tail->next = b_addrs->head;
    b_addrs->head = b_addrs->tail;
    b_list->next = NULL;
    b_addrs->tail = b_list;
    if(print_rr != 1)
        write(1,"rrb\n",4);
}


void    ft_rrr(f_list *a_addrs, f_list *b_addrs)
{
    ft_rra(a_addrs, 1);
    ft_rrb(b_addrs, 1);
    write(1,"rrr\n",4);
}