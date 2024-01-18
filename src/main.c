/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:14:39 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 05:28:32 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	display(t_minishell *minishell)
{
	char	*pwd;
	char	**tab;

	pwd = getcwd(NULL, 0);
	tab = ft_split(pwd, '/');
	if (minishell->ret == 0)
		ft_printf(GREEN"・"BLUE" %s$> "RESET, tab[ft_tabsize(tab) - 1]);
	else
		ft_printf(RED"・"BLUE" %s$> "RESET, tab[ft_tabsize(tab) - 1]);
	free(pwd);
	ft_freetab(tab);
}

int	main(int ac, char **av, char **env)
{
	int			len;
	t_minishell	minishell;

	initialize(&minishell, ac, av, env);
	while (minishell.exit == false)
	{
		display(&minishell);
		minishell.line = get_next_line(minishell.fds[0]);
		if (minishell.line)
		{
			len = ft_strlen(minishell.line);
			minishell.line[len - 1] = '\0';
		}
		parse(&minishell);
		free(minishell.line);
	}
	free_all(&minishell);
	return (0);
}
