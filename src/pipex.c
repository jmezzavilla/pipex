/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:17:29 by jmezzavilla       #+#    #+#             */
/*   Updated: 2023/09/02 20:16:17 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	fd[2];
	int	status;

	if (argc != 5)
		error_msg("Invalid number of arguments", EXIT_FAILURE);
	if (pipe(fd) < 0)
		error_msg("Pipe error", EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		error_msg("Fork error", EXIT_FAILURE);
	else if (pid == 0)
		child(argv[1], fd, argv[2], envp);
	else
		parent(argv[4], fd, argv[3], envp);
	waitpid(-1, &status, 0);
	return (WEXITSTATUS(status));
}
