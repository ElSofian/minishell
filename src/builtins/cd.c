/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:41:02 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 05:53:30 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home(t_minishell *minishell)
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

int	ft_cd(t_minishell *minishell)
{
	int		i;
	char	*target;
	char	*pwd;

	i = 0;
	if (ft_strncmp(minishell->line, "cd ~", 4) == 0
	|| (ft_strncmp(minishell->line, "cd", 2) == 0
		&& ft_strlen(minishell->line) == 2))
		target = get_home(minishell);
	else if (ft_strncmp(minishell->line, "..", 2) == 0)
		target = ft_strdup(minishell->line);
	else if (ft_strncmp(minishell->line, "cd", 2) == 0)
		target = ft_strdup(minishell->line + 3);
	else if (ft_strncmp(minishell->line, ".", 1) == 0)
		return (0);
	else
		target = ft_strdup(minishell->line);
	if (chdir(target) == -1)
		return (get_error(minishell));
	pwd = getcwd(NULL, 0);
	while (minishell->env[i])
	{
		if (ft_strncmp(minishell->env[i], "PWD=", 4) == 0)
		{
			free(minishell->env[i]);
			minishell->env[i] = ft_strjoin("PWD=", pwd);
			return (free(pwd), free(target), 0);
		}
		i++;
	}
	return (free(pwd), free(target), 0);
}
