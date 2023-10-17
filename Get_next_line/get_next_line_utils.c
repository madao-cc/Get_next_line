/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:34:39 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/17 17:05:05 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*result;
	
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = str[i];
	result[++i] = '\0';
	return (result);
}

char	*ft_broom(char *str)
{
	int		i;
	char	*result;
	int		j;
	int		length;

	length = ft_strlen(str);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	result = malloc(sizeof(char) * (length - i) + 1);
	j = 0;
	while (str[i])
	{
		result[j++] = str[++i];
	}
	result[j] = '\0';
	free(str);
	return (result);
}
