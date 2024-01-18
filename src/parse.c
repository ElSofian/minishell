/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:08:59 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 07:02:13 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_cd_shortcut(char *cmd)
{
	struct stat	path_stat;

	if (stat(cmd, &path_stat) == 0)
	{
		if (S_ISDIR(path_stat.st_mode))
			return (0);
		else
			return (1);
	}
	return (1);
}

static void	builtins(t_minishell *minishell, char *cmd)
{
	if (ft_strncmp(cmd, "echo", 4) == 0)
		minishell->ret = ft_echo(minishell, cmd);
	else if (ft_strncmp(cmd, "cd", 2) == 0 || ft_strncmp(cmd, "..", 2) == 0
		|| ft_strncmp(cmd, ".", 1) == 0 || ft_strncmp(cmd, "~", 1) == 0
		|| check_cd_shortcut(cmd) == 0)
		minishell->ret = ft_cd(minishell);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		minishell->ret = ft_pwd(minishell);
	else if (ft_strncmp(cmd, "export", 6) == 0)
		minishell->ret = ft_export(minishell, cmd + 7);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		minishell->ret = ft_unset(minishell, cmd + 6);
	else if (ft_strncmp(cmd, "env", 3) == 0)
		minishell->ret = ft_env(minishell);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		minishell->ret = ft_exit(minishell);
	else if (ft_strncmp(cmd, "setcolor", 8) == 0)
		minishell->ret = ft_setcolor(minishell, cmd + 9);
	else if (ft_strncmp(cmd, "history", 7) == 0)
		minishell->ret = ft_history(minishell);
	else
		minishell->ret = NOT_BUILTIN;
}

void	parse(t_minishell *minishell)
{
	int	i;

	i = 0;
	if (minishell->line[0] == '\0')
		return ;
	builtins(minishell, minishell->line);
	if (minishell->ret == NOT_BUILTIN)
		minishell->ret = exec_cmd(minishell);
	lstadd_back(&minishell->history, lstnew(minishell->line));
}
