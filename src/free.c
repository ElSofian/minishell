/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:54:22 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 11:13:26 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_minishell *minishell)
{
	free(minishell->color);
	free(minishell->path);
	ft_freetab(minishell->av);
	ft_freetab(minishell->env);
	lstclear(&minishell->history, free);
}
