/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:39:01 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/21 14:01:29 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	run_cmd(t_minishell *minishell, char *cmd_name)
{
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(cmd_name, ' ');
	cmd_path = get_cmd_path(cmd[0], minishell->env);
	if (execve(cmd_path, cmd, minishell->env) == -1)
		return (ft_freetab(cmd), free(cmd_path),
			get_error(minishell, NULL));
	ft_freetab(cmd);
	free(cmd_path);
	return (0);
}

static int	run_single_cmd(t_minishell *minishell, char *cmd_name)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		return (get_error(minishell, NULL));
	pid = fork();
	if (pid < 0)
		return (get_error(minishell, NULL));
	if (pid == 0)
	{
		close(fd[0]);
		close(fd[1]);
		if (run_cmd(minishell, cmd_name))
			printf("error\n");
		exit(EXIT_SUCCESS);
	}
	close(fd[1]);
	wait(&pid);
	return (0);
}

static int	create_pipe(t_minishell *minishell, char *cmd_name)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		return (get_error(minishell, NULL));
	pid = fork();
	if (pid < 0)
		return (get_error(minishell, NULL));
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (run_cmd(minishell, cmd_name))
			printf("error\n");
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	waitpid(pid, NULL, 0);
	return (0);
}

int	exec_cmd(t_minishell *minishell)
{
	int		i;
	char	**cmds;

	i = 0;
	cmds = ft_split(minishell->line, '|');
	if (!cmds)
		return (get_error(minishell, NULL));
	minishell->fds[0] = dup(STDIN_FILENO);
	minishell->fds[1] = dup(STDOUT_FILENO);
	dup2(minishell->fds[0], STDIN_FILENO);
	while (i < ft_tabsize(cmds) - 1 && cmds[i])
	{
		if (create_pipe(minishell, cmds[i]) != 0)
			return (ft_freetab(cmds), get_error(minishell, NULL));
		i++;
	}
	dup2(minishell->fds[1], STDOUT_FILENO);
	run_single_cmd(minishell, cmds[i]);
	ft_freetab(cmds);
	return (0);
}
