/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:26:56 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 03:33:39 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check(char *cmd, int *quoted, bool *display_line)
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
		&& cmd[ft_strlen(cmd) - 2] != cmd[i + 1])
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

static char	*get_str(char *cmd, bool display_line, int quoted)
{
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * ft_strlen(cmd) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (cmd[j])
	{
		if ((quoted == 1 && cmd[j] == '"')
			|| (quoted == 2 && cmd[j] == '\'')
			|| (!display_line && cmd[j] == '\n'))
			break ;
		str[j] = cmd[j];
		j++;
	}
	if (j == ft_strlen(cmd) - 2 && display_line && quoted)
	{
		str[j] = '\n';
		str[j + 1] = '\0';
	}
	else
		str[j] = '\0';
	return (str);
}

int	ft_echo(char *cmd)
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
	str = get_str(cmd + i, display_line, quoted);
	if (!str)
		return (1);
	ft_printf("%s", str);
	return (0);
}
