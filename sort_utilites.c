/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:25:27 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/14 21:17:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_idx_num_b(f_list *b_addrs, int push)
{
	t_list	*list;
	t_list	*list2;
	int		idx;

	idx = 1;
	if (push > b_addrs->head->num && push < b_addrs->tail->num)
		idx = 0;
	else if (push > b_addrs->max || push < b_addrs->min)
		idx = ft_get_idx(b_addrs, b_addrs->max);
	else
	{
		list = b_addrs->head;
		list2 = b_addrs->head->next;
		while (list->num < push || list2->num > push)
		{
			list = list->next;
			list2 = list2->next;
			idx++;
		}
	}
	return (idx);
}

int	ft_idx_num_a(f_list *a_addrs, int push)
{
	t_list	*list;
	t_list	*list2;
	int		idx;

	list = a_addrs->head;
	idx = 1;
	if (push < a_addrs->head->num && push > a_addrs->tail->num)
		idx = 0;
	else if (push > a_addrs->max || push < a_addrs->min)
		idx = ft_get_idx(a_addrs, a_addrs->min);
	else
	{
		list2 = list->next;
		while (list->next && (list->num > push || list2->num < push))
		{
			list = list->next;
			if (list)
				list2 = list->next;
			idx++;	
		}
	}
	return (idx);
}

int	ft_is_sorted(f_list *addrs)
{
	t_list  *list;
    int     num;

    list = addrs->head;
	num = list->num;
	while (list)
	{
		if (num > list->num)
			return (0);
		num = list->num;
		list = list->next;
	}
	return (1);
}