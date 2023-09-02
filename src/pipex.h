/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:18:12 by jmezzavilla       #+#    #+#             */
/*   Updated: 2023/09/02 16:47:02 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

void	ft_clean(char **str);
void	error_msg(char *str, int err);
void	child(char *file, int fd[2], char *cmd, char **envp);
void	parent(char *file, int fd[2], char *cmd, char **envp);
void	execute(char *cmd, char **envp);

#endif
