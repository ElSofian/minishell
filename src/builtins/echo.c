/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:26:56 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/21 18:22:36 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	size(t_minishell *minishell, char *cmd, bool display_line)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;
	char	*sub;

	i = -1;
	size = 0;
	while (cmd[++i])
	{
		if (cmd[i] == '$')
		{
			j = 0;
			while (cmd[i + j] && cmd[i + j] != ' ')
				j++;
			sub = ft_substr(cmd, i + 1, j - 1);
			tmp = get_env(minishell, sub);
			if (tmp)
				size += ft_strlen(tmp);
			free(tmp);
			free(sub);
			i += j;
		}
		else
			size += 1;
	}
	if (display_line)
		size += 1;
	return (size + 1);
}

static int	check(char *cmd,
			int *quoted, bool *display_line)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	if (cmd[i + 1] == '-' && cmd[i + 2] != 'n')
		return (1);
	else if (cmd[i + 1] == '-' && cmd[i + 2] == 'n')
		*display_line = false;
	if ((cmd[i + 1] == '"' || cmd[i + 1] == '\'')
		&& cmd[ft_strlen(cmd) - 1] != cmd[i + 1])
		return (1);
	else
	{
		if (cmd[i + 1] == '"' || cmd[i + 4] == '"')
			*quoted = 1;
		else if (cmd[i + 1] == '\'' || cmd[i + 4] == '\'')
			*quoted = 2;
	}
	return (0);
}

static void	environement_variables(t_minishell *minishell, char **str,
								char *cmd, int *j)
{
	int		i;
	int		k;
	char	*sub;
	char	*tmp;

	i = 0;
	k = 0;
	while (cmd[*j + k] && cmd[*j + k] != ' ')
		k++;
	sub = ft_substr(cmd, *j + 1, k - 1);
	tmp = get_env(minishell, sub);
	if (tmp)
	{
		free(sub);
		sub = ft_strjoin(tmp, " ");
		while (sub[i])
		{
			(*str)[*j] = sub[i];
			i++;
			(*j)++;
		}
	}
	else
		(*j) += k;
	free(sub);
	free(tmp);
}

static char	*get_str(t_minishell *minishell, char *cmd,
				bool display_line, int quoted)
{
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * size(minishell, cmd, display_line));
	if (!str)
		return (NULL);
	j = 0;
	while (cmd[j])
	{
		if (cmd[j] == '$')
			environement_variables(minishell, &str, cmd, &j);
		else
		{
			if ((quoted == 1 && cmd[j] == '"')
				|| (quoted == 2 && cmd[j] == '\'')
				|| (!display_line && cmd[j] == '\n'))
				break ;
			str[j] = cmd[j];
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}

int	ft_echo(t_minishell *minishell, char *cmd)
{
	int		i;
	int		quoted;
	bool	display_line;
	char	*str;

	i = 0;
	quoted = 0;
	display_line = true;
	check(cmd, &quoted, &display_line);
	while (cmd[i] && cmd[i] != ' ')
		i++;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (!display_line)
		i += 3;
	if (quoted)
		i++;
	str = get_str(minishell, cmd + i, display_line, quoted);
	if (!str)
		return (get_error(minishell, NULL));
	if (display_line)
		ft_printf("%s\n", str);
	else
		ft_printf("%s", str);
	return (free(str), 0);
}
