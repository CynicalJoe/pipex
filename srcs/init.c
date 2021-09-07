/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:14:36 by gtournay          #+#    #+#             */
/*   Updated: 2021/09/07 11:14:39 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*copy_path(char *path)
{
	char	*new;
	size_t	len;

	len = ft_strlen(path);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, path, len + 1);
	return (new);
}

void	get_path(char **env, t_pipex *pip)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH", env[i], 4))
			break ;
		i++;
	}
	if (!env[i])
	{
		free_pip(pip);
		write(0, "Couldnt find $PATH\n", 20);
		exit(1);
	}
	pip->path = ft_split(env[i], ':');
	if (!remove_path(pip->path))
	{
		write(0, "Malloc error\n", 14);
		free_pip(pip);
		exit(1);
	}
}

t_pipex	*init_struct(char **argv, char **env)
{
	t_pipex	*pip;

	pip = malloc(sizeof(t_pipex));
	pip->file1 = copy_path(argv[1]);
	pip->file2 = copy_path(argv[4]);
	pip->cmd1 = ft_split(argv[2], ' ');
	pip->cmd2 = ft_split(argv[3], ' ');
	if (!pip->file1 || !pip->file2 || !pip->cmd1 || !pip->cmd2)
	{
		free_pip(pip);
		write(0, "Malloc error\n", 14);
		exit(1);
	}
	get_path(env, pip);
	pip->cmd1[0] = check_cmd_loc(pip->path, pip->cmd1[0]);
	pip->cmd1 = cat_filename(pip->cmd1, pip->file1);
	pip->file1 = NULL;
	pip->cmd2[0] = check_cmd_loc(pip->path, pip->cmd2[0]);
	if (!pip->cmd1 || !pip->cmd2)
	{
		free_pip(pip);
		write(0, "Error while processing arguments\n", 34);
		exit(1);
	}
	return (pip);
}
