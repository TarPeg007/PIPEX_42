/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfellahi <sfellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:46:11 by sfellahi          #+#    #+#             */
/*   Updated: 2024/05/25 14:37:04 by sfellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(void)

{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

char	*check_full_path(char *command)

{
	if (command[0] == '/')
	{
		if (access(command, X_OK) == -1)
		{
			perror("access");
			exit(1);
		}
		return (command);
	}
	return (NULL);
}

char	**extract_paths(char *environment[])

{
	int	i;

	i = 0;
	while (environment[i] != NULL)
	{
		if ((ft_strncmp(environment[i], "PATH=", 5) == 0))
			return (ft_split(environment[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*check_and_build_path(char *path, char *command)

{
	char	*full_path;
	char	*final_path;

	full_path = ft_strjoin(path, "/");
	if (full_path == NULL)
		return (NULL);
	final_path = ft_strjoin(full_path, command);
	free(full_path);
	if (final_path == NULL)
		return (NULL);
	if (access(final_path, F_OK | X_OK) == 0)
		return (final_path);
	free(final_path);
	return (NULL);
}

void	cleanup_paths(char **paths)

{
	int	i;

	i = 0;
	while (paths[i] != NULL)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
