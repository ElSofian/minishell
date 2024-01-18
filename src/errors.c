/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:32:07 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 06:13:03 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_error(t_minishell *minishell, char *error)
{
	if (error)
	{
		ft_printf("Error: %s\n", error);
		minishell->ret = 1;
	}
	else
	{
		ft_printf("Error: %s\n", strerror(errno));
		minishell->ret = errno;
	}
	return (1);
}
