/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:35:14 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 02:55:57 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H
# include <global_utils.h>
# include <ft_lsts.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

int		print_exports(t_env *env);
int		validate_arg(char *arg);
void	concate_env(char *key, char *value);
void	append_to_env(t_env **env, char *key, char *value, int equal_sign);
int		validate_var_name(char *str);
int		is_bad_env_name_start(char c);
int		ft_is_alphanum_underscore(char *str);
int		handle_concate_case(char *line);
#endif
