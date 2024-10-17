/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_ba_utilites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 01:25:27 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/14 01:27:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cal_rarb_a(f_list *a_addrs, f_list *b_addrs, int num)
{
	int	idx;

	idx = ft_idx_num_a(a_addrs, num);
	if (idx < ft_get_idx(b_addrs, num))
		idx = ft_get_idx(b_addrs, num);
	return (idx);
}

int	ft_cal_rrarb_a(f_list *a_addrs, f_list *b_addrs, int num)
{
	int	idx;

	idx = 0;
	if (ft_idx_num_a(a_addrs, num))
		idx = a_addrs->size - ft_idx_num_a(a_addrs, num);
	idx += ft_get_idx(b_addrs, num);
	return (idx);
}

int	ft_cal_rrarrb_a(f_list *a_addrs, f_list *b_addrs, int num)
{
	int	idx;

	idx = 0;
	if (ft_idx_num_a(a_addrs, num))
		idx = a_addrs->size - ft_idx_num_a(a_addrs, num);
	if ((idx < (b_addrs->size - ft_get_idx(b_addrs, num)))
		&& ft_get_idx(b_addrs, num))
		idx = b_addrs->size - ft_get_idx(b_addrs, num);
	return (idx);
}

int	ft_cal_rarrb_a(f_list *a_addrs, f_list *b_addrs, int num)
{
	int	idx;

	idx = 0;
	if (ft_get_idx(b_addrs, num))
		idx = b_addrs->size - ft_get_idx(b_addrs, num);
	idx += ft_idx_num_a(a_addrs, num);
	return (idx);
}

int	ft_cal_rotate_ba(f_list *a_addrs, f_list *b_addrs)
{
	t_list	*list;
	int		idx;

	list = b_addrs->head;
	idx = ft_cal_rrarrb_a(a_addrs, b_addrs, list->num);
	while (list)
	{
		if (idx > ft_cal_rarb_a(a_addrs, b_addrs, list->num))
			idx = ft_cal_rarb_a(a_addrs, b_addrs, list->num);
		if (idx > ft_cal_rrarrb_a(a_addrs, b_addrs, list->num))
			idx = ft_cal_rrarrb_a(a_addrs, b_addrs, list->num);
		if (idx > ft_cal_rarrb_a(a_addrs, b_addrs, list->num))
			idx = ft_cal_rarrb_a(a_addrs, b_addrs, list->num);
		if (idx > ft_cal_rrarb_a(a_addrs, b_addrs, list->num))
			idx = ft_cal_rrarb_a(a_addrs, b_addrs, list->num);
		list = list->next;
	}
	return (idx);
}