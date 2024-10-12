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

void	ft_free_link(t_list *a_list)
{
	t_list *current;
	
	current = a_list;
	while (current)
	{
		current = current->next;
		free(a_list);
		a_list = current;
	}
}

t_list  *ft_set_a_b(int *numbers, f_list *a_list, f_list *b_list)
{
    t_list  *new_node;
    int     i;
    
    i = 0;
    a_list->tail = NULL;
    while (++i <= numbers[0])
    {
        new_node = malloc(sizeof(t_list));
        if (!new_node)
            return (ft_free_link(a_list->head), NULL);
        if (i == 1)
            a_list->head = new_node;
        new_node->content = numbers[i];
        new_node->rank = i;
        new_node->next = NULL;
        if (a_list->tail != NULL)
            a_list->tail->next = new_node;
        a_list->tail = new_node;
    }
	b_list->head = NULL;
	b_list->tail = NULL;
	a_list->size = numbers[0];
	free(numbers);
    return(a_list->head);
}