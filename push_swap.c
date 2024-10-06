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
	
	int		*numbers;
	int		i;
	t_list	*lista;
	t_list	*listb;

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
	lista = malloc(sizeof(t_list));
	if (!lista)
		return (free(lista), NULL);
	i = 1;
	while (i != numbers[0])
	{
			lista->content = numbers[i];
			lista->next = NULL;
	}
	write(1, "\n", 1);
	free(numbers);
	return (0);
}
