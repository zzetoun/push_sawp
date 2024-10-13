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

void	ft_free_link(f_list *list)
{
	t_list *current;
	
    if (!list->head)
        return ;
	current = list->head;
	while (current)
	{
		current = current->next;
        list->head->content = 0;
		free(list->head);
		list->head = current;
	}
}

void    ft_indxing(f_list *addrs)
{
    t_list *list;
    int     idx;

    list = addrs->head;
    idx = 1;
    while (list)
    {
        list->idx = idx;
        list = list->next;
    }
}

int ft_get_idx(f_list *addrs ,int content)
{
    t_list  *list;

    ft_indxing(addrs);
    list = addrs->head;
    while (list && list->content != content)
        list = list->next;
    return(list->idx);
    
}

void    ft_max_min(f_list *addrs)
{
    t_list  *list;

    list = addrs->head;
    addrs->max = list->content;
    addrs->min = list->content;
    while (list)
    {
        if (list->content > addrs->max)
            addrs->max = list->content;
        else if (list->content < addrs->min)
            addrs->min = list->content;
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
        new_node->content = num[i];
        new_node->idx = i;
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
