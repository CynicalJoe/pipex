/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:28:52 by gtournay          #+#    #+#             */
/*   Updated: 2021/09/07 11:28:53 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*check_cmd_loc(char **path, char *cmd)
{
	int		fd;
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	while (path[i])
	{
		if (new)
			free(new);
		new = parse_path(path[i], cmd);
		if (!new)
			return (NULL);
		fd = open(new, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			free(cmd);
			return (new);
		}
		close(fd);
		i++;
	}
	return (NULL);
}

char	**cat_filename(char **cmd, char *file)
{
	char	**new;
	int		i;

	i = 0;
	if (!cmd[0])
		return (NULL);
	while (cmd[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (cmd[i])
	{
		new[i] = cmd[i];
		i++;
	}
	new[i++] = file;
	new[i++] = NULL;
	free(cmd);
	return (new);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_pip(t_pipex *pip)
{
	if (pip)
	{
		if (pip->cmd1)
			free_array(pip->cmd1);
		if (pip->cmd2)
			free_array(pip->cmd2);
		if (pip->path)
			free_array(pip->path);
		if (pip->file2)
			free(pip->file2);
		if (pip->file1)
			free(pip->file1);
		free(pip);
	}
}
