/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utilties.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:17:30 by zzetoun           #+#    #+#             */
/*   Updated: 2024/09/20 12:17:31 by zzetoun          ###   ########.ae       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
		current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (size);
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	return (size + 1);
}
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (lst)
		del(lst->content);
	free(lst);
}
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*aux;

	current = *lst;
	if (!current)
		free(current);
	while (current)
	{
		aux = current;
		del(current->content);
		current = current->next;
		free(aux);
	}
	*lst = NULL;
}