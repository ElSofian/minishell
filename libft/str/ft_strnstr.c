/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:14:13 by soelalou          #+#    #+#             */
/*   Updated: 2023/11/09 18:52:26 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	*return_error(int err)
{
	if (err == 1)
		ft_printf("First verification failed in ft_strnstr().\n");
	else if (err == 2)
		ft_printf("The length of to_find is bigger than n - length of str.\n");
	return (NULL);
}

char	*ft_strnstr(const char *str, const char *tf, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str || (n == 0 && (!tf || *tf)))
		return (return_error(1));
	if (n == 0 || !tf || ft_strlen(tf) == 0)
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == tf[j] && (i + j) < n)
		{
			j++;
			if (!tf[j])
				return ((char *)str + i);
		}
		i++;
	}
	if (ft_strlen(tf) > (n - i))
		return (return_error(2));
	return (NULL);
}
