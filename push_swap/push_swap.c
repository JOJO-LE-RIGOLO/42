/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:20:01 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/06 16:26:24 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_veriflst(t_list **li)
{
	if (!(*li) || !(*li)->value)
	{
		ft_lstclear(li);
		msg_error("Error\n");
	}
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_list	*ft_initlist(int ac, char **av, int mod)
{
	t_list	*li;
	int		i;

	if (mod == 1)
	{
		li = ft_lstnew(ft_atoi(av[1]));
		i = 2;
	}
	else
	{
		li = ft_lstnew(ft_atoi(av[0]));
		i = 1;
		ac = tab_len(av);
	}
	ft_veriflst(&li);
	while (i < ac)
	{
		ft_lstadd_back(&li, ft_lstnew(ft_atoi(av[i])));
		ft_veriflst(&li);
		i++;
	}
	return (li);
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**tab;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		ft_verif(tab_len(tab), tab, 0);
		a = ft_initlist(ac, tab, 2);
		freetab(tab);
	}
	else
	{
		a = ft_initlist(ac, av, 1);
		ft_verif(ac, av, 1);
	}
	while (a)
	{
		ft_printf("%i\n", a->value);
		a = a->next;
	}
	ft_lstclear(&a);
}
