/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_rotate_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:44:49 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/14 11:44:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_go_rarb(f_list *a_addrs, f_list *b_addrs, int value, char flag)
{
	if (flag == 'a')
	{
		while (a_addrs->head->num != value && ft_idx_num_b(b_addrs, value) > 0)
			ft_rr(a_addrs, b_addrs);
		while (a_addrs->head->num != value)
			ft_ra(a_addrs, 0);
		while (ft_idx_num_b(b_addrs, value) > 0)
			ft_rb(b_addrs, 0);
		ft_pb(a_addrs, b_addrs);
	}
	else
	{
		while (b_addrs->head->num != value && ft_idx_num_a(a_addrs, value) > 0)
			ft_rr(a_addrs, b_addrs);
		while (b_addrs->head->num != value)
			ft_rb(b_addrs, 0);
		while (ft_idx_num_a(a_addrs, value) > 0)
			ft_ra(a_addrs, 0);
		ft_pa(a_addrs, b_addrs);
	}
	return (-1);
}

int	ft_go_rrarb(f_list *a_addrs, f_list *b_addrs, int value, char flag)
{
	if (flag == 'a')
	{
		while (a_addrs->head->num != value)
			ft_rra(a_addrs, 0);
		while (ft_idx_num_b(b_addrs, value) > 0)
			ft_rb(b_addrs, 0);
		ft_pb(a_addrs, b_addrs);
	}
	else
	{
		while (ft_idx_num_a(a_addrs, value) > 0)
			ft_rra(a_addrs, 0);
		while (b_addrs->head->num != value && b_addrs->size > 1)
			ft_rb(b_addrs, 0);
		ft_pa(a_addrs, b_addrs);
	}
	return (-1);
}

int	ft_go_rarrb(f_list *a_addrs, f_list *b_addrs, int value, char flag)
{
	if (flag == 'a')
	{
		while (a_addrs->head->num != value)
			ft_ra(a_addrs, 0);
		while (ft_idx_num_b(b_addrs, value) > 0)
			ft_rrb(b_addrs, 0);
		ft_pb(a_addrs, b_addrs);
	}
	else
	{
		while (ft_idx_num_a(a_addrs, value) > 0)
			ft_ra(a_addrs, 0);
		while (b_addrs->head->num != value)
			ft_rrb(b_addrs, 0);
		ft_pa(a_addrs, b_addrs);
	}
	return (-1);
}

int	ft_go_rrarrb(f_list *a_addrs, f_list *b_addrs, int value, char flag)
{
	if (flag == 'a')
	{
		while (a_addrs->head->num != value && ft_get_idx(b_addrs, value) > 0)
			ft_rrr(a_addrs, b_addrs);
		while (a_addrs->head->num != value)
			ft_rra(a_addrs, 0);
		while (ft_idx_num_b(b_addrs, value) > 0)
			ft_rrb(b_addrs, 0);
		ft_pb(a_addrs, b_addrs);
	}
	else
	{
		while (b_addrs->head->num != value && ft_idx_num_a(a_addrs, value) > 0)
			ft_rrr(a_addrs, b_addrs);
		while (b_addrs->size != 1 && b_addrs->head->num != value)
			ft_rrb(b_addrs, 0);
		while (ft_idx_num_a(a_addrs, value) != 0)
			ft_rra(a_addrs, 0);
		ft_pa(a_addrs, b_addrs);
	}
	return (-1);
}
