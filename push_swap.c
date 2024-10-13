/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:44:49 by zzetoun           #+#    #+#             */
/*   Updated: 2024/10/12 11:44:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_print_stack(f_list *addrs)
{
	t_list *tmp = addrs->head;
	int 	i;

	printf("size: %d\n", addrs->size); 
	i = 1;
	while (tmp)
	{
		printf("list[%d]: %d\n", i , tmp->content);
		tmp = tmp->next;
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	f_list	a_addrs;
	f_list	b_addrs;
	int		*numbers;

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
	ft_set_a_b(numbers, &a_addrs, &b_addrs);
	printf("\na list\n");
	ft_print_stack(&a_addrs);
	ft_pb(&a_addrs,&b_addrs);
	ft_pb(&a_addrs,&b_addrs);
	ft_pb(&a_addrs,&b_addrs);

	printf("\nb list\n");
	ft_print_stack(&b_addrs);

	ft_rrb(&b_addrs, 0);
	printf("\nb list\n");
	ft_print_stack(&b_addrs);

	ft_rra(&a_addrs, 0);
	printf("\na list\n");
	ft_print_stack(&a_addrs);

	ft_rrr(&a_addrs, &b_addrs);
	printf("\nb list\n");
	ft_print_stack(&b_addrs);
	printf("\na list\n");
	ft_print_stack(&a_addrs);


	ft_free_link(&a_addrs);
	ft_free_link(&b_addrs);


	write(1, "\n", 1);
	return (0);
}
