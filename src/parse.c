/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:08:59 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 05:56:41 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_cd_shortcut(char *cmd)
{
	struct stat path_stat;

	if (stat(cmd, &path_stat) == 0) {
		if (S_ISDIR(path_stat.st_mode))
			return (0);
		else
			return (1);
	}
	return (1);
}

static int	builtins(t_minishell *minishell, char *cmd)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(cmd, "echo", 4) == 0)
		ret = ft_echo(minishell, cmd);
	else if (ft_strncmp(cmd, "cd", 2) == 0
		|| ft_strncmp(cmd, "..", 2) == 0
		|| ft_strncmp(cmd, ".", 1) == 0
		|| ft_strncmp(cmd, "~", 1) == 0
		|| check_cd_shortcut(cmd) == 0)
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
		minishell->ret = exec_cmd(minishell);
}
