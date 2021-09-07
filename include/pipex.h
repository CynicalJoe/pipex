/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:32:50 by gtournay          #+#    #+#             */
/*   Updated: 2021/09/07 11:32:51 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	char	*file1;
	char	*file2;
	char	**cmd1;
	char	**cmd2;
	char	**path;
}	t_pipex;

char	*remove_path(char **path);

void	get_path(char **env, t_pipex *pip);

void	free_pip(t_pipex *pip);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*check_cmd_loc(char **path, char *cmd);

char	*parse_path(char *path, char *cmd);

char	**cat_filename(char **cmd, char *file);

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	**ft_split(char const *s, char c);

t_pipex	*init_struct(char **argv, char **env);

#endif
