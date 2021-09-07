/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:15:00 by gtournay          #+#    #+#             */
/*   Updated: 2021/09/07 11:15:02 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	firstcmd(t_pipex *pip, int *pi, int *fd, char **env)
{
	dup2(fd[0], 0);
	dup2(pi[1], 1);
	close(fd[0]);
	close(pi[1]);
	close(pi[0]);
	strerror(execve(pip->cmd1[0], pip->cmd1, env));
	close(fd[0]);
	close(fd[1]);
	close(pi[0]);
	close(pi[1]);
	unlink(pip->file2);
	exit(1);
}

void	seccmd(t_pipex *pip, int *pi, int *fd, char **env)
{
	wait(NULL);
	dup2(pi[0], 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(pi[0]);
	close(pi[1]);
	strerror(execve(pip->cmd2[0], pip->cmd2, env));
	close(fd[0]);
	close(fd[1]);
	close(pi[0]);
	close(pi[1]);
	unlink(pip->file2);
	exit(1);
}

void	pipex(t_pipex *pip, char **env)
{
	int		fd[2];
	int		pi[2];
	int		error;
	pid_t	childp;

	error = 0;
	pipe(pi);
	fd[0] = open(pip->file1, O_RDONLY);
	fd[1] = open(pip->file2, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd[0] > 0 || fd[1] > 0)
	{
		childp = fork();
		if (childp == 0)
			firstcmd(pip, pi, fd, env);
		childp = fork();
		if (childp == 0)
			seccmd(pip, pi, fd, env);
		close(fd[0]);
		close(fd[1]);
		close(pi[0]);
		close(pi[1]);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pip;
	int		i;

	i = 0;
	if (argc != 5)
	{	
		write(0, "Wrong number of arguments\n", 27);
		return (0);
	}
	pip = init_struct(argv, env);
	pipex(pip, env);
	free_pip(pip);
	return (0);
}
