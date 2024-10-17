/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:25:27 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/14 19:27:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_b_three(f_list *a_addrs, f_list *b_addrs)
{
    t_list  *list;
    int     cost;

    while (a_addrs->size > 3 && !ft_is_sorted(a_addrs))
    {
        list = a_addrs->head;
        cost = ft_cal_rotate_ab(a_addrs, b_addrs);
        while (cost >= 0)
        {       
            if (cost == ft_cal_rarb_b(a_addrs, b_addrs, list->num))
                cost = ft_go_rarb(a_addrs, b_addrs, list->num, 'a');
            else if (cost == ft_cal_rrarrb_b(a_addrs, b_addrs, list->num))
                cost = ft_go_rrarrb(a_addrs, b_addrs, list->num, 'a');
            else if (cost == ft_cal_rarrb_b(a_addrs, b_addrs, list->num))
                cost = ft_go_rarrb(a_addrs, b_addrs, list->num, 'a');
            else if (cost == ft_cal_rrarb_b(a_addrs, b_addrs, list->num))
                cost = ft_go_rrarb(a_addrs, b_addrs, list->num, 'a');
            else
                list = list->next;
            
        }
    }
}

void    ft_sort_is_three(f_list *a_addrs)
{
	if (a_addrs->min == a_addrs->head->num)
	{
		ft_rra(a_addrs, 0);
		ft_sa(a_addrs, 0);
	}
	else if (a_addrs->max == a_addrs->head->num)
	{
		ft_ra(a_addrs, 0);
		if (!ft_is_sorted(a_addrs))
            ft_sa(a_addrs, 0);
	}
	else
	{
		if (ft_get_idx(a_addrs, a_addrs->max) == 1)
			ft_rra(a_addrs, 0);
		else
			ft_sa(a_addrs, 0);
	}
}

void    ft_sort_b(f_list *a_addrs, f_list *b_addrs)
{
    int count;

    count = 3;
    while (--count != 0)
        if (a_addrs->size > 3 && !ft_is_sorted(a_addrs))
            ft_pb(a_addrs, b_addrs);
    if (a_addrs->size > 3 && !ft_is_sorted(a_addrs))
        ft_sort_b_three(a_addrs, b_addrs);
    if (!ft_is_sorted(a_addrs))
        ft_sort_is_three(a_addrs);
}

void    ft_sort_a(f_list *a_addrs, f_list *b_addrs)
{
    t_list  *list;
    t_list  *b_list;
    int     type;

    list = b_addrs->head;
    b_list = list;
    while (b_list)
    {
        list = b_addrs->head;
        type = ft_cal_rotate_ba(a_addrs, b_addrs);
        while (type >= 0)
        {
            if (type == ft_cal_rarb_a(a_addrs, b_addrs, list->num))
                type = ft_go_rarb(a_addrs, b_addrs, list->num, 'b');
            else if (type == ft_cal_rrarb_a(a_addrs, b_addrs, list->num))
                type = ft_go_rrarrb(a_addrs, b_addrs, list->num, 'b');
            else if (type == ft_cal_rrarrb_a(a_addrs, b_addrs, list->num))
                type = ft_go_rarrb(a_addrs, b_addrs, list->num, 'b');
            else if (type == ft_cal_rrarb_a(a_addrs, b_addrs, list->num))
                type = ft_go_rrarb(a_addrs, b_addrs, list->num, 'b');
            else
                list = list->next;
        }
        b_list = b_addrs->head;
    }
}

void	ft_sort_final(f_list *a_addrs, f_list *b_addrs)
{
    int     idx;

    if (a_addrs->size == 2)
        ft_sa(a_addrs, 0);
    else
    {
        ft_sort_b(a_addrs, b_addrs);
        ft_sort_a(a_addrs, b_addrs);
        idx = ft_get_idx(a_addrs, a_addrs->min);
        if (idx < a_addrs->size - idx)
        {
            while (a_addrs->head->num != a_addrs->min)
                ft_ra(a_addrs, 0);
        }
        else
        {
            while (a_addrs->head->num != a_addrs->min)
                ft_rra(a_addrs, 0);
        }
    }
}