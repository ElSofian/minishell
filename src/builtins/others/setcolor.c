/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:07:14 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 06:26:54 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_setcolor(t_minishell *minishell, char *color)
{
	free(minishell->color);
	minishell->color = NULL;
	if (ft_strcmp(color, "red") == 0 || ft_strcmp(color, "RED") == 0)
		minishell->color = ft_strdup(RED);
	else if (ft_strcmp(color, "green") == 0 || ft_strcmp(color, "GREEN") == 0)
		minishell->color = ft_strdup(GREEN);
	else if (ft_strcmp(color, "yellow") == 0 || ft_strcmp(color, "YELLOW") == 0)
		minishell->color = ft_strdup(YELLOW);
	else if (ft_strcmp(color, "blue") == 0 || ft_strcmp(color, "BLUE") == 0
	|| ft_strcmp(color, "reset") == 0 || ft_strcmp(color, "RESET") == 0)
		minishell->color = ft_strdup(BLUE);
	else if (ft_strcmp(color, "purple") == 0 || ft_strcmp(color, "PURPLE") == 0)
		minishell->color = ft_strdup(PURPLE);
	else if (ft_strcmp(color, "pink") == 0 || ft_strcmp(color, "PINK") == 0)
		minishell->color = ft_strdup(PINK);
	else
	{
		minishell->color = ft_strdup(BLUE);
		return (get_error(minishell, "Wrong color provided.\n\
There is the available colors : "RED"red"RESET", "GREEN"green"RESET", \
"YELLOW"yellow"RESET", "BLUE"blue"RESET", "PURPLE"purple"RESET",\
"PINK" pink"RESET" or reset to get back to the original color."));
	}
	return (0);
}