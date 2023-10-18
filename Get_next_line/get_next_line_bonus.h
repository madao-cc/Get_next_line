/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:02:12 by marvin            #+#    #+#             */
/*   Updated: 2023/10/18 14:02:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strdup(char *str);
int	ft_strlen(char *str);
char	*get_next_line(int fd);
int	ft_check_newline(char *str);
char	*ft_save_in_temp(char *receive, char *str);
char	*ft_broom(char *str);
void	*ft_clean(char **buffer, char **str);
void	*ft_memalloc(size_t nitems, size_t size);

# endif