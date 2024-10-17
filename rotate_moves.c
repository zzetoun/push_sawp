/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:44:49 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/12 11:44:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_ra(f_list *a_addrs, int print)
{
    t_list  *a_list;
    
    if (!a_addrs->head)
        return ;
    a_list = a_addrs->head->next;
    a_addrs->head->next = NULL;
    a_addrs->tail->next = a_addrs->head;
    a_addrs->tail = a_addrs->tail->next;
    a_addrs->head = a_list;
    ft_indxing(a_addrs);
    if(print != 1)
        write(1,"ra\n",3);
}

void    ft_rb(f_list *b_addrs, int print)
{
    t_list  *b_list;

    if (!b_addrs->head)
        return ;
    b_list = b_addrs->head->next;
    b_addrs->head->next = NULL;
    b_addrs->tail->next = b_addrs->head;
    b_addrs->tail = b_addrs->tail->next;
    b_addrs->head = b_list;
    ft_indxing(b_addrs);
    if(print != 1)
        write(1,"rb\n",3);
}


void    ft_rr(f_list *a_addrs, f_list *b_addrs)
{
if (!a_addrs->head || !b_addrs->head)
        return ;
    ft_ra(a_addrs, 1);
    ft_rb(b_addrs, 1);
    write(1,"rr\n",3);
}