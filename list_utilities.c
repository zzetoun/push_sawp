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
	
	current = list->head;
	while (current)
	{
		current = current->next;
		free(list->head);
		list->head = current;
	}
}

void 	ft_set_a_b(int *numbers, f_list *a_addrs, f_list *b_addrs)
{
    t_list  *new_node;
    int     i;
    
    i = 0;
    a_addrs->tail = NULL;
    while (++i <= numbers[0])
    {
        new_node = malloc(sizeof(t_list));
        if (!new_node)
			return (ft_free_link(a_addrs));
        if (i == 1)
            a_addrs->head = new_node;
        new_node->content = numbers[i];
        new_node->rank = i;
        new_node->next = NULL;
        if (a_addrs->tail != NULL)
            a_addrs->tail->next = new_node;
        a_addrs->tail = new_node;
    }
	b_addrs->head = NULL;
	b_addrs->tail = NULL;
	b_addrs->size = 0;
	a_addrs->size = numbers[0];
	free(numbers);
}
