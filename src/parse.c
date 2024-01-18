/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:08:59 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 04:42:57 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	builtins(t_minishell *minishell, char *cmd)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(cmd, "echo", 4) == 0)
		ret = ft_echo(minishell, cmd);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		ret = ft_cd(minishell);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		ret = ft_pwd(minishell);
	else if (ft_strncmp(cmd, "export", 6) == 0)
		ret = ft_export(minishell, cmd + 7);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		ret = ft_unset(minishell, cmd + 6);
	else if (ft_strncmp(cmd, "env", 3) == 0)
		ret = ft_env(minishell);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		ret = ft_exit(minishell);
	else
		ret = NOT_BUILTIN;
	return (ret);
}

void	parse(t_minishell *minishell)
{
	int	i;

	i = 0;
	if (minishell->line[0] == '\0')
		return ;
	minishell->ret = builtins(minishell, minishell->line);
	if (minishell->ret == NOT_BUILTIN)
	{
		minishell->ret = exec_cmd(minishell);
	}
}
