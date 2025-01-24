/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:27:52 by jojo              #+#    #+#             */
/*   Updated: 2025/01/24 18:44:36 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void *ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	else if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, size * count);
	return (ptr);
}

void    clear_data(t_data **data)
{
    free(*data);
    *data = NULL;
}

t_data  *ft_newdata(void)
{
    t_data  *data;

    data = ft_calloc(sizeof(*data), 1);
    if (!data)
        return (NULL);
    data->nb_philo = 0;
    data->time_die = 0;
    data->time_eat = 0;
    data->time_sleep = 0;
    data->nb_of_eating = 0;
    return (data);
}