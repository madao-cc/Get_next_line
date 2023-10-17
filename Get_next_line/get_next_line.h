/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:07:32 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/17 16:44:22 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
int		ft_check_newline(char *str);
char	*ft_save_in_temp(char *receive, char *str);
char	*ft_broom(char *str);

# endif
