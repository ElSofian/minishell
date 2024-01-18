/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:32:07 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 04:22:45 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_error(t_minishell *minishell)
{
	ft_printf("Error: %s\n", strerror(errno));
	minishell->ret = errno;
	return (1);
}
