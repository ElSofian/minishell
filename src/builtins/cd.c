/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:41:02 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 10:55:58 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_home(t_minishell *minishell)
{
	int	i;

	i = 0;
	while (minishell->env[i])
	{
		if (ft_strncmp(minishell->env[i], "HOME=", 5) == 0)
			return (ft_strdup(minishell->env[i] + 5));
		i++;
	}
	return (NULL);
}

static char	*set_target(t_minishell *minishell)
{
	char	*target;

	if (ft_strncmp(minishell->line, "cd ~", 4) == 0
		|| (ft_strncmp(minishell->line, "cd", 2) == 0
			&& ft_strlen(minishell->line) == 2))
		target = get_home(minishell);
	else if (ft_strncmp(minishell->line, "..", 2) == 0)
		target = ft_strdup(minishell->line);
	else if (ft_strncmp(minishell->line, "cd", 2) == 0)
		target = ft_strdup(minishell->line + 3);
	else if (ft_strncmp(minishell->line, ".", 1) == 0)
		return (NULL);
	else
		target = ft_strdup(minishell->line);
	return (target);
}

int	ft_cd(t_minishell *minishell)
{
	int		i;
	char	*target;
	char	*pwd;

	i = 0;
	target = set_target(minishell);
	if (!target)
		return (0);
	if (chdir(target) == -1)
		return (get_error(minishell, NULL));
	pwd = getcwd(NULL, 0);
	while (minishell->env[i])
	{
		if (ft_strncmp(minishell->env[i], "PWD=", 4) == 0)
		{
			free(minishell->env[i]);
			minishell->env[i] = ft_strjoin("PWD=", pwd);
			free(minishell->path);
			minishell->path = ft_strdup(pwd);
			return (free(pwd), free(target), 0);
		}
		i++;
	}
	return (free(pwd), free(target), 0);
}
