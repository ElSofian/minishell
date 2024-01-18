/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:03:26 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 06:10:34 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static char	*get_path(t_minishell *minishell)
// {
// 	int		i;
// 	char	*path;

// 	i = 0;
// 	path = NULL;
// 	while (minishell->env[i])
// 	{
// 		if (ft_strncmp(minishell->env[i], "PATH=", 5) == 0)
// 			path = ft_strdup(minishell->env[i] + 5);
// 		i++;
// 	}
// 	return (path);
// }

void	initialize(t_minishell *minishell, int ac, char **av, char **env)
{
	minishell->fds[0] = 0;
	minishell->fds[1] = 1;
	minishell->ret = 0;
	minishell->ac = ac;
	minishell->exit = false;
	minishell->line = NULL;
	minishell->color = ft_strdup(BLUE);
	minishell->av = ft_tabdup(av);
	minishell->env = ft_tabdup(env);
	minishell->path = getcwd(NULL, 0);
}
