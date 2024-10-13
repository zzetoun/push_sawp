/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushj_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:44:49 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/11 11:44:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pa(f_list *a_addrs, f_list *b_addrs)
{
    t_list  *b_list;

    if (!b_addrs->head)
        return ;
    b_list = b_addrs->head->next;
    b_addrs->head->next = a_addrs->head;
    a_addrs->head = b_addrs->head;
    b_addrs->head = b_list;
    b_addrs->size--;
    a_addrs->size++;
    ft_max_min(a_addrs);
    ft_indxing(a_addrs);
    write(1,"pa\n",3);
}

void    ft_pb(f_list *a_addrs, f_list *b_addrs)
{
    t_list  *a_list;

    if (!a_addrs->head)
        return ;
    a_list = a_addrs->head->next;
    a_addrs->head->next = b_addrs->head;
    b_addrs->head = a_addrs->head;
    a_addrs->head = a_list;
    a_addrs->size--;
    b_addrs->size++;
    a_list = b_addrs->head;
    while (a_list)
    {
        if(!a_list->next)
            b_addrs->tail = a_list;
        a_list = a_list->next;
    }
    ft_max_min(b_addrs);
    ft_indxing(b_addrs);
    write(1,"pb\n",3);
}
