/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:00:22 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/17 23:51:39 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_minishell *minishell)
{
	int		i;

	i = 0;
	if (!minishell->env)
		return (1);
	while (minishell->env[i])
	{
		ft_printf("%s\n", minishell->env[i]);
		i++;
	}
	return (0);
}
