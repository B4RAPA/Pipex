/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:35:54 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/17 11:59:31 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"
# include <errno.h>

void	execute(char **ag, char **envp);
char	*split_path(const char *cmd, char **envp);
void	child(int *fd, char **envp, char **ag);
void	parent_process(char **argv, char **envp, int *fd);
void	error(char *msg);
void	error_2(char *msg);

#endif