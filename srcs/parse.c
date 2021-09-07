/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:24:54 by gtournay          #+#    #+#             */
/*   Updated: 2021/09/07 11:24:55 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*remove_path(char **path)
{
	char	*new;
	size_t	len;

	len = ft_strlen(path[0]) - 4;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	ft_strlcpy(new, &path[0][5], len);
	free(path[0]);
	path[0] = new;
	return (new);
}

char	*parse_path(char *path, char *cmd)
{
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	if (!new)
		return (NULL);
	ft_strlcpy(new, path, ft_strlen(path) + 1);
	ft_strlcat(new, "/", ft_strlen(new) + 2);
	ft_strlcat(new, cmd, ft_strlen(new) + ft_strlen(cmd) + 2);
	return (new);
}
