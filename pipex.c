/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfellahi <sfellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:30:13 by sfellahi          #+#    #+#             */
/*   Updated: 2024/05/25 15:51:06 by sfellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_child_process(char **args, char **envp, int *pipe_fds)

{
	int	input_file_descriptor;

	input_file_descriptor = open(args[1], O_RDONLY, 0777);
	if (input_file_descriptor == -1)
	{
		perror("Error opening input file");
		handle_error();
	}
	dup2(input_file_descriptor, STDIN_FILENO);
	close(input_file_descriptor);
	dup2(pipe_fds[1], STDOUT_FILENO);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	execute(args[2], envp);
	perror("Error executing child process");
}

void	execute_child_process_2(char **args, char **envp, int *pipe_fds)

{
	int	input_file_descriptor2;

	input_file_descriptor2 = open(args[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (input_file_descriptor2 == -1)
	{
		perror("Error opening input file");
		handle_error();
	}
	dup2(input_file_descriptor2, STDOUT_FILENO);
	close(input_file_descriptor2);
	dup2(pipe_fds[0], STDIN_FILENO);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	execute(args[3], envp);
	perror("Error executing child process");
}

void	fork_and_execute_processes(char **argv, char **envp)

{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		handle_error();
	pid1 = fork();
	if (pid1 == -1)
		handle_error();
	if (pid1 == 0)
		execute_child_process(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		handle_error();
	if (pid2 == 0)
		execute_child_process_2(argv, envp, fd);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)

{
	if (argc == 5)
		fork_and_execute_processes(argv, envp);
	else
	{
		perror("Usage: Incorrect file1 cmd1 cmd2 file2\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
