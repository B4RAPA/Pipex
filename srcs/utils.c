/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:29:18 by lfabel            #+#    #+#             */
/*   Updated: 2024/12/04 11:11:31 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*split_path(const char *cmd, char **envp)
{
	char	*path_part;
	char	*path;
	char	**tmp;
	int		i;

	i = 0;
	while (ft_strnstr(*envp, "PATH", 4) == 0)
		envp++;
	tmp = ft_split(*envp + 5, ':');
	i = 0;
	while (tmp[i++])
	{
		path_part = ft_strjoin(tmp[i], "/");
		path = ft_strjoin(path_part, cmd);
		free (path_part);
		if (access(path, F_OK) == 0)
			return (path);
		if (!tmp[i + 1])
			error_2((char *) cmd);
		free (path);
	}
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	return (0);
}

void	error(char *msg)
{
	ft_printf("zsh: %s: %s\n", strerror(errno), msg);
	exit(EXIT_FAILURE);
}

void	error_2(char *msg)
{
	ft_printf("zsh: Command not found: %s\n", msg);
	exit (EXIT_FAILURE);
}

void	execute(char **argv, char **envp)
{
	char	*path;
	char	**cmd;
	int		i;

	i = -1;
	cmd = ft_split(*argv, ' ');
	path = split_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free (cmd[i]);
		free (cmd);
		error("\n");
	}
	if (execve(path, cmd, envp) == -1)
		error(path);
}
