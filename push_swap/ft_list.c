#include "push_swap.h"

t_list	*ft_lstnew(int new_value)
{
	t_list	*li;

	li = malloc(sizeof(*li));
	if (!li)
		return (NULL);
	li->value = new_value;
	li->next = NULL;
	return (li);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*li;

	if (!lst || !new)
		return ;
	li = ft_lstlast(*lst);
	if (!li)
		*lst = new;
	else
		li->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}