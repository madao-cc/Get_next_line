/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:01:58 by marvin            #+#    #+#             */
/*   Updated: 2023/10/18 14:01:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_save_in_temp(char *buffer, char *str)
{
	int		i;
	int		j;
	int		lenght;
	char		*result;

	if (!str)
		str = ft_memalloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	lenght = ft_strlen(buffer) + ft_strlen(str);
	result = ft_memalloc((lenght + 1), sizeof(char));
	j = 0;
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		result[i++] = buffer[j++];
	}
	free(str);
	return (result);
}

int	ft_check_newline(char *str)
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

void	*ft_clean(char **buffer, char **str)
{
	free(*str);
	free(*buffer);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	int		count;
	char		*buffer;
	char		*final;

	count = 1;
	if ((fd < 0 && fd > 4096) || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_memalloc((BUFFER_SIZE + 1), sizeof(char));
	while (ft_check_newline(str) == 0 && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (ft_clean(&str[fd], &buffer));
		buffer[count] = '\0';
		str[fd] =  ft_save_in_temp(buffer[fd], str);
	}
	final = ft_strdup(str[fd]);
	str[fd] = ft_broom(str[fd]);
	free(buffer);
	return (final);
}
