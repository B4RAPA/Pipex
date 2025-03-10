/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:28:37 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/17 11:59:14 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error ("\n");
		pid1 = fork();
		if (pid1 == -1)
			error ("\n");
		if (pid1 == 0)
			child(fd, envp, argv);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putendl_fd("Failure amount of arguments is incorrect", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
	}
	return (0);
}

void	child(int *fd, char **envp, char **ag)
{
	int	input;

	input = open(ag[1], O_RDONLY);
	if (input == -1)
		error(ag[1]);
	dup2 (fd[1], STDOUT_FILENO);
	dup2 (input, STDIN_FILENO);
	close (fd[0]);
	execute (&ag[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output == -1)
	{
		ft_printf("zsh: %s: %s\n", strerror(errno), argv[4]);
		exit (1);
	}
	dup2 (output, STDOUT_FILENO);
	dup2 (fd[0], STDIN_FILENO);
	close (fd[1]);
	execute (&argv[3], envp);
}
