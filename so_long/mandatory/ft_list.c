/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:19:54 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/15 14:47:16 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_map	*ft_lstnew(char *new_line, int len)
{
	t_map	*li;

	li = ft_calloc(sizeof(*li), 1);
	if (!li)
		return (NULL);
	li->line = ft_strdup(new_line);
	li->len_line = len;
	li->empty = 0;
	li->wall = 0;
	li->item = 0;
	li->exit = 0;
	li->player = 0;
	li->target = '0';
	li->next = NULL;
	return (li);
}

void	ft_mapclear(t_map **lst)
{
	t_map	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->line);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_lstadd_front(t_map **lst, t_map *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map	*li;

	if (!lst || !new)
		return ;
	li = ft_lstlast(*lst);
	if (!li)
		*lst = new;
	else
		li->next = new;
}

t_map	*ft_lstlast(t_map *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
