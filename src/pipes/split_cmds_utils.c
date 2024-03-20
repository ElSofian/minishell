/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:11:13 by soelalou          #+#    #+#             */
/*   Updated: 2024/03/20 03:12:33 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***alloc_tab(int nb)
{
	char	***tab;

	tab = (char ***) malloc((nb + 2) * sizeof (char **));
	if (!tab)
		return (NULL);
	tab[0] = NULL;
	return (tab);
}
