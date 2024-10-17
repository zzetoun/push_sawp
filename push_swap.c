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

	printf("size: %d\n", addrs->size); 
	printf("max is:%d \nmin is:%d \n", addrs->max, addrs->min);
	while (tmp)
	{
		printf("list[%d] list->idx[%d]: %d\n",ft_get_idx(addrs, tmp->num) ,tmp->idx , tmp->num);
		tmp = tmp->next;
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
	ft_set_a_b(0, numbers, &a_addrs, &b_addrs);
	if (!ft_is_sorted(&a_addrs))
	 	ft_sort_final(&a_addrs, &b_addrs);
	ft_print_stack(&a_addrs);
	ft_print_stack(&b_addrs);
	ft_free_link(&a_addrs);
	ft_free_link(&b_addrs);


	write(1, "\n", 1);
	return (0);
}