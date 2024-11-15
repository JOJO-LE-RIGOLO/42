/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:52:53 by jojo              #+#    #+#             */
/*   Updated: 2024/11/15 14:01:01 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define MIN -2147483648
# define MAX 2147483647

# include <stdarg.h>
# include <unistd.h>

int     ft_printf(const char *format, ...);

#endif