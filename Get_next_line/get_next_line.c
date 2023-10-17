/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:58:57 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/17 17:06:32 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_in_temp(char *receive, char *str)
{
	int		i;
	int		j;
	int		lenght;
	char	*result;

	i = 0;
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[i] = '\0';
	}
	lenght = ft_strlen(receive) + ft_strlen(str);
	result = malloc(sizeof(char) * (lenght + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	while (receive[j])
	{
		result[i++] = receive[j++];
	}
	result[i] = '\0';
	free(str);
	return (result);
}

int		ft_check_newline(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			sz;
	char		*receive;
	char		*final;

	sz = 1;
	if (fd < 1)
		return (NULL);
	receive = malloc(sizeof(BUFFER_SIZE + 1));
	if (!receive)
		return (0);
	while (ft_check_newline(str) == 0 && sz > 0)
	{
		sz = read(fd, receive, BUFFER_SIZE);
		receive[sz] = '\0';
		str =  ft_save_in_temp(receive, str);
	}
	final = ft_strdup(str);
	str = ft_broom(str);
	free(receive);
	return (final);
}
