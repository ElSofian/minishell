/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:26:56 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 04:16:57 by soelalou         ###   ########.fr       */
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

static char	*get_str(char *cmd, bool display_line, int quoted)
{
	int		j;
	char	*str;

	if (display_line)
		str = (char *)malloc(sizeof(char) * ft_strlen(cmd) + 2);
	else
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
	if (display_line)
		str[j++] = '\n';
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
	str = get_str(cmd + i, display_line, quoted);
	if (!str)
		return (get_error(minishell));
	ft_printf("%s", str);
	return (0);
}
