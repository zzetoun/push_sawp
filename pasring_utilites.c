/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasring_utilites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:25:27 by zzetoun           #+#    #+#             */
/*   Updated: 2024/07/07 21:17:50 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dig(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	ft_counter(char *s, char c, int *counter)
{
	int	idx;

	idx = -1;
	while (++idx < ft_strlen(s))
		(*counter) += (s[idx] == c);
}

char	*ft_strjoin(char *str, char *s)
{
	char	*join;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s || !str)
		return (free(str), NULL);
	join = malloc((ft_strlen(str) + (ft_strlen(s) + 2)));
	if (!join)
		return (free(str), free(join), NULL);
	while (str[++i])
		join[i] = str[i];
	while (s[j] && s[j] == ' ')
		j++;
	while (s[j])
	{
		if (s[j] != ' ' || (s[j + 1] != ' ' && s[j + 1] != '\0'))
			join[i++] = s[j];
		j++;
	}
	if (join[i - 1] != ' ')
		join[i++] = ' ';
	join[i] = '\0';
	return (free(str), join);
}

int	*ft_assign(char *str, char c, int *sp_str)
{
	int			idx;
	int			jdx;
	int			sign;
	long		nb;

	idx = 0;
	jdx = 1;
	while (str[idx] && idx != ft_strlen(str) - 1)
	{
		nb = 0;
		while (str[idx] == c)
			idx++;
		if (str[idx] && str[idx] != c)
		{
			sign = 1 - 2 * (str[idx] == '-');
			idx += (str[idx] == '-' || str[idx] == '+');
			while (dig(str[idx]))
				nb = (10 * nb) + (str[idx++]) - '0';
			nb *= sign;
			if (nb > INT_MAX || nb < INT_MIN)
				return (free(sp_str), NULL);
		}
		sp_str[jdx++] = nb;
	}
	return (sp_str);
}
