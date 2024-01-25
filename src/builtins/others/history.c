/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:53:11 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 06:59:27 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_history(t_minishell *minishell)
{
	t_history	*tmp;

	tmp = minishell->history;
	while (tmp)
	{
		if (tmp->cmd)
			ft_printf("- %s\n", tmp->cmd);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (0);
}
