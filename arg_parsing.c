/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:27:56 by zzetoun           #+#    #+#             */
/*   Updated: 2024/09/06 18:27:57 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid(char **argv, int i, int j, int flag)
{
	char	c;

	while (argv[++i])
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (!(dig(c) || c == ' ' || c == '-' || c == '+'))
				return (0);
			else if ((c == '-' || c == '+') && !(dig(argv[i][j + 1])))
				return (0);
			else if (j > 0 && (c == '-' || c == '+') && (argv[i][j - 1] != 32))
				return (0);
			else if (c == ' ' || c == '-' || c == '+')
				j++;
			else if (dig(c))
				flag = ++j;
		}
		if (j == 0 || flag == 0)
			return (0);
	}
	return (1);
}

static int	ft_double(int *pars, int len)
{
	int	i;
	int	j;

	i = 1;
	
	while (i != len)
	{
		j = i + 1;
		while (j != len)
		{
			if (pars[i] == pars[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_parse(char **argv)
{
	int		i;
	char	*str;
	int		*pars;
	int		counter;

	i = 0;
	counter = 1;
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (argv[++i])
		str = ft_strjoin(str, argv[i]);
	ft_counter(str, ' ', &counter);
	pars = malloc(sizeof(int) * counter);
	if (!pars)
		return (free(str), NULL);
	pars = ft_assign(str, ' ', pars);
	if (!pars || !ft_double(pars, counter))
		return (free(str),free(pars), NULL);
	pars[0] = counter - 1;
	return (free(str), pars);
}
