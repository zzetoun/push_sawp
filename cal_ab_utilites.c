/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_ab_utilites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:25:27 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/14 01:27:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cal_rarb_b(f_list *a_addrs, f_list *b_addrs, int num)
{
	int	idx;

	idx = ft_idx_num_b(b_addrs, num);
	if (idx < ft_get_idx(a_addrs, num))
		idx = ft_get_idx(a_addrs, num);
	return (idx);
}

int	ft_cal_rrarb_b(f_list *a_addrs, f_list *b_addrs, int num)
{
	int	idx;

	idx = 0;
	if (ft_get_idx(a_addrs, num))
		idx = a_addrs->size - ft_get_idx(a_addrs, num);
	idx += ft_idx_num_b(b_addrs, num);
	return (idx);
}

int	ft_cal_rrarrb_b(f_list *a_addrs, f_list *b_addrs, int num)
{
	int	idx;

	idx = 0;
	if (ft_idx_num_b(b_addrs, num))
		idx = b_addrs->size - ft_idx_num_b(b_addrs, num);
	if ((idx < a_addrs->size - ft_get_idx(a_addrs, num)) 
			&& ft_get_idx(a_addrs, num))
		idx = a_addrs->size - ft_get_idx(a_addrs, num);
	return (idx);
}

int	ft_cal_rarrb_b(f_list *a_addrs, f_list *b_addrs, int num)
{
	int	idx;

	idx = 0;
	if (ft_idx_num_b(b_addrs, num))
		idx = b_addrs->size - ft_idx_num_b(b_addrs, num);
	idx += ft_get_idx(a_addrs, num);
	return (idx);
}

int	ft_cal_rotate_ab(f_list *a_addrs, f_list *b_addrs)
{
	t_list	*list;
	int		idx;

	list = a_addrs->head;
	idx = ft_cal_rrarrb_b(a_addrs, b_addrs, list->num);
	while (list)
	{
		if (idx > ft_cal_rarb_b(a_addrs, b_addrs, list->num))
			idx = ft_cal_rarb_b(a_addrs, b_addrs, list->num);
		if (idx > ft_cal_rrarrb_b(a_addrs, b_addrs, list->num))
			idx = ft_cal_rrarrb_b(a_addrs, b_addrs, list->num);
		if (idx > ft_cal_rarrb_b(a_addrs, b_addrs, list->num))
			idx = ft_cal_rarrb_b(a_addrs, b_addrs, list->num);
		if (idx > ft_cal_rrarb_b(a_addrs, b_addrs, list->num))
			idx = ft_cal_rrarb_b(a_addrs, b_addrs, list->num);
		list = list->next;
	}
	return (idx);
}