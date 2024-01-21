/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:05:57 by soelalou          #+#    #+#             */
/*   Updated: 2024/01/18 13:06:31 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_strsplit(char *str, char *separator)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!str || !separator)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] && !ft_strchr(separator, str[i]))
			tab[j][k++] = str[i++];
		tab[j][k] = '\0';
		while (str[i] && ft_strchr(separator, str[i]))
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);	
}