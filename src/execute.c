/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:46:09 by jealves-          #+#    #+#             */
/*   Updated: 2023/09/02 16:46:37 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char **cmd, char *path, char **envp)
{
	int		i;
	char	**path_splitted;
	char	*path_cmd;
	char	*path_slash;

	i = 0;
	path_splitted = ft_split(path, ':');
	while (path_splitted[i])
	{
		path_slash = ft_strjoin(path_splitted[i], "/");
		path_cmd = ft_strjoin(path_slash, cmd[0]);
		free(path_slash);
		if (access(path_cmd, F_OK) != -1)
			execve(path_cmd, cmd, envp);
		free(path_cmd);
		i++;
	}
	ft_clean(path_splitted);
}

void	execute_path(char **cmd, char **envp)
{
	int		i;
	char	**envp_splitted;

	i = 0;
	while (envp[i])
	{
		envp_splitted = ft_split(envp[i], '=');
		if (ft_strncmp(envp_splitted[0], "PATH", 4) == 0)
		{
			execute_cmd(cmd, envp_splitted[1], envp);
		}
		ft_clean(envp_splitted);
		i++;
	}
	ft_strlen(cmd[0]);
}

void	execute(char *cmd, char **envp)
{
	char	**splitted;

	splitted = ft_split(cmd, ' ');
	if (splitted[0][0] == '/')
	{
		execve(splitted[0], splitted, envp);
	}
	else
	{
		if (!splitted[0])
			error_msg("Command not found", 127);
		else
			execute_path(splitted, envp);
	}
	ft_clean(splitted);
	error_msg("Command not found", 127);
}
