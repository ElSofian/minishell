/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:39:01 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 00:39:32 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_path_dirs(char **env)
{
	int		i;
	char	**dirs;

	i = 0;
	while (ft_strncmp("PATH", env[i], 4) != 0)
		i++;
	dirs = ft_split(env[i] + 5, ':');
	if (!dirs)
		return (NULL);
	return (dirs);
}

static char	*get_cmd_path(char *cmd, char **env)
{
	int		i;
	int		len;
	char	*path;
	char	**dirs;

	i = -1;
	path = NULL;
	dirs = get_path_dirs(env);
	if (!dirs)
		return (NULL);
	while (dirs[++i])
	{
		len = ft_strlen(dirs[i]) + ft_strlen(cmd) + 2;
		path = (char *)malloc(sizeof(char) * len);
		if (!path)
			return (ft_freetab(dirs), NULL);
		ft_strcpy(path, dirs[i]);
		ft_strcat(path, "/");
		ft_strcat(path, cmd);
		ft_printf("path[%d]: %s\n", i, path);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_printf("path found: %s\n", i, path);
			return (ft_freetab(dirs), path);
		}
		free(path);
	}
	return (ft_freetab(dirs), NULL);
}

int	exec_cmd(t_minishell *minishell)
{
	int		fd[2];
	char	**cmd;
	pid_t	pid;

	if (pipe(fd) < 0)
		return (1);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		cmd = ft_split(minishell->line, ' ');
		close(fd[0]);
		close(fd[1]);
		execve(get_cmd_path(cmd[0], minishell->env), cmd, minishell->env);
		ft_freetab(cmd);
		exit(EXIT_SUCCESS);
	}
	close(fd[1]);
	wait(&pid);
	return (0);
}
