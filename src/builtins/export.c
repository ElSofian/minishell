/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:38:38 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 01:04:34 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	length_before_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i - 1);
}

static int	check(t_minishell *minishell, char *arg)
{
	int		i;
	char	*var_name;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	var_name = (char *)malloc(sizeof(char) * (i + 1));
	if (!var_name)
		return (1);
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		var_name[i] = arg[i];
		i++;
	}
	if (!arg[i] || arg[0] == '=' || arg[ft_strlen(arg) - 2] == '=')
		return (1);
	i = 0;
	while (minishell->env[i])
	{
		if (!ft_strncmp(minishell->env[i], var_name, length_before_equal(arg)))
			ft_unset(minishell, var_name);
		i++;
	}
	return (0);
}

static char	*ft_strdup_without_n(char *src)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_export(t_minishell *minishell, char *arg)
{
	int		i;
	char	**new_env;

	check(minishell, arg);
	i = -1;
	new_env = (char **)malloc(sizeof(char *)
			* (ft_tabsize(minishell->env) + 2));
	if (!new_env)
		return (1);
	while (minishell->env[++i])
	{
		new_env[i] = ft_strdup(minishell->env[i]);
		if (!new_env[i])
			return (1);
	}
	new_env[i] = ft_strdup_without_n(arg);
	if (!new_env[i])
		return (1);
	new_env[i + 1] = NULL;
	ft_freetab(minishell->env);
	minishell->env = ft_tabdup(new_env);
	if (!minishell->env)
		return (1);
	ft_freetab(new_env);
	return (0);
}
