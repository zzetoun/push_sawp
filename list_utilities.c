/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utilties.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:30 by zzetoun           #+#    #+#             */
/*   Updated: 2024/09/20 12:17:31 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_link(f_list *addrs)
{
	t_list *list;
	
    list = addrs->head;
	while (list)
	{
		list = list->next;
        addrs->head->num = 0;
		free(addrs->head);
		addrs->head = list;
	}
}

void    ft_indxing(f_list *addrs)
{
    t_list *list;
    int     idx;

    list = addrs->head;
    idx = 0;
    if (list)
        list->idx = idx;
    while (list)
    {
        list->idx = idx;
        list = list->next;
        idx++;
    }
}

int ft_get_idx(f_list *addrs ,int num)
{
    t_list  *list;

    ft_indxing(addrs);
    list = addrs->head;
    while (list->next && list->num != num)
        list = list->next;
    if (list->num == num)
        return (list->idx);
    else
        return (0);
    
}

void    ft_max_min(f_list *addrs)
{
    t_list  *list;
    
    if (addrs->size == 0)
    {
        addrs->max = 0;
        addrs->min = 0;
        return ;
    }
    list = addrs->head;
    addrs->max = addrs->head->num;
    addrs->min = addrs->head->num;
    while (list && addrs->size > 1)
    {
        if (list->num > addrs->max)
            addrs->max = list->num;
        else if (list->num < addrs->min)
            addrs->min = list->num;
        list = list->next;
    }
}

void 	ft_set_a_b(int i, int *num, f_list *a_addrs, f_list *b_addrs)
{
    t_list  *new_node;
    
    a_addrs->tail = NULL;
    while (++i <= num[0])
    {
        new_node = malloc(sizeof(t_list));
        if (!new_node)
			return (ft_free_link(a_addrs));
        if (i == 1)
            a_addrs->head = new_node;
        new_node->num = num[i];
        new_node->idx = i - 1;
        new_node->next = NULL;
        if (a_addrs->tail != NULL)
            a_addrs->tail->next = new_node;
        a_addrs->tail = new_node;
    }
    a_addrs->tail->next = NULL;
	b_addrs->head = NULL;
	b_addrs->tail = NULL;
	b_addrs->size = 0;
	a_addrs->size = num[0];
	free(num);
    ft_max_min(a_addrs);
}
