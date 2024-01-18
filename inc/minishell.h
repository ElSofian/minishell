/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:11:22 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 04:42:20 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"

# define RESET "\033[0;39m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define PINK "\033[1;38;5;200m"

# define NOT_BUILTIN 6000000

typedef struct s_history
{
	char	**cmds;
}	t_history;

typedef struct s_minishell
{
	int			ret;
	int			ac;
	int			fds[2];
	bool		exit;
	bool		display;
	char		*line;
	char		*path;
	char		**env;
	char		**av;
	t_history	history;
}	t_minishell;

int		get_error(t_minishell *minishell);
void	initialize(t_minishell *minishell, int ac, char **av, char **env);
void	parse(t_minishell *minishell);

// Pipes
int		exec_cmd(t_minishell *minishell);

// Builtins
int		ft_cd(t_minishell *minishell);
int		ft_echo(t_minishell *minishell, char *cmd);
int		ft_env(t_minishell *minishell);
int		ft_exit(t_minishell *minishell);
int		ft_export(t_minishell *minishell, char *arg);
int		ft_pwd(t_minishell *minishell);
int		ft_unset(t_minishell *minishell, char *arg);

#endif