/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:19 by jojo              #+#    #+#             */
/*   Updated: 2025/01/27 15:30:00 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
je dois redefinir ma strucutre du coups de dois changer comment je verif tout
et apres faire la routine + la fonction de verif si un philo meurt.
*/

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_newdata(ft_atoi(av[1]));
	if (!data)
		return (msg_error(-1), 0);
	if (verif_init(ac, av, &data) == 1)
		return (0);
	//philo(data);
	clear_data(&data);
}
