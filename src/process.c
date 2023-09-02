/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:47:52 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/02 17:17:00 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char *file, int fd[2], char *cmd, char **envp)
{
	int	fin;

	fin = open(file, O_RDONLY);
	if (fin < 0)
		error_msg("Open file error", EXIT_FAILURE);
	dup2(fin, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fin);
	execute(cmd, envp);
	close(fd[1]);
}

void	parent(char *file, int fd[2], char *cmd, char **envp)
{
	int	fout;

	fout = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fout < 0)
		error_msg("Open file error", EXIT_FAILURE);
	dup2(fout, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fout);
	execute(cmd, envp);
	close(fd[0]);
}
