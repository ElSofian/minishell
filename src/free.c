/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:54:22 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 05:16:32 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lstdelone(t_history *lst, void (*del)(void *))
{
	if (!lst || !del)
	{
		if (!lst)
			ft_printf("Argument lst is NULL in ft_lstdelone() function.\n");
		if (!del)
			ft_printf("Argument function del is NULL in ft_lstdelone().\n");
		return ;
	}
	del(lst->cmd);
	free(lst);
}

static void	lstclear(t_history **lst, void (*del)(void *))
{
	t_history	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			lstdelone(*lst, del);
			(*lst) = tmp;
		}
	}
}

void	free_all(t_minishell *minishell)
{
	free(minishell->line);
	free(minishell->path);
	ft_freetab(minishell->av);
	ft_freetab(minishell->env);
	lstclear(&minishell->history, free);
}