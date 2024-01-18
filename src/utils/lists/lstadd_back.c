/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:47:21 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 06:58:55 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstadd_back(t_history **lst, t_history *new)
{
	t_history	*tmp;

	if (!lst || !new)
	{
		if (!lst)
			ft_printf("Argument lst is NULL in lstadd_back() function.\n");
		if (!new)
			ft_printf("Argument new is NULL in lstadd_back() function.\n");
		return ;
	}
	tmp = lstlast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}
