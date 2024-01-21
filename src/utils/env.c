/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:25:36 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/21 17:51:48 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(t_minishell *minishell, char *name)
{
	int		i;
	char	*env;

	i = 0;
	while (minishell->env[i])
	{
		if (ft_strncmp(minishell->env[i], name, ft_strlen(name)) == 0)
		{
			env = ft_strdup(minishell->env[i] + ft_strlen(name) + 1);
			return (env);
		}
		i++;
	}
	return (NULL);
}
