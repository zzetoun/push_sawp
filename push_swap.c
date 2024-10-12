/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:44:49 by zzetoun           #+#    #+#             */
/*   Updated: 2024/09/05 11:44:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	
	t_list  *a_list;
	f_list	a_addrs;
	f_list	b_addrs;
	int		*numbers;
	int		i;

	if (argc < 1 || !ft_valid(argv, 0, 0, 0))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	numbers = ft_parse(argv);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	a_list = ft_set_a_b(numbers, &a_addrs, &b_addrs);
	printf("size: %d\n",a_addrs.size);
	i = 1;
	while (a_list)
	{
			printf("list[%d]: %d\n", i , a_list->content);
			a_list = a_list->next;
			i++;
	}
	write(1, "\n", 1);
	ft_free_link(a_list);
	return (0);
}
