/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:32:07 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/21 16:11:54 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_error(t_minishell *minishell, char *error)
{
	if (error)
		ft_printf("Error: %s\n", error);
	else
		ft_printf("Error: %s\n", strerror(errno));
	minishell->ret = -1;
	return (minishell->ret);
}
