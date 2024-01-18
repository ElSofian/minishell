/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:51:21 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 06:58:51 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_history	*lstnew(char *cmd)
{
	t_history	*list;

	list = (t_history *)malloc(sizeof(t_history));
	if (!list)
	{
		ft_printf("Argument lst is NULL in lstnew() function.\n");
		return (NULL);
	}
	list->cmd = ft_strdup(cmd);
	list->next = NULL;
	return (list);
}
