/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfellahi <sfellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:40:42 by sfellahi          #+#    #+#             */
/*   Updated: 2024/05/25 15:13:17 by sfellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_and_check_path(char **all_path, char *cmd)

{
	char	*final_path;
	int		i;

	i = 0;
	while (all_path[i] != NULL)
	{
		final_path = check_and_build_path(all_path[i], cmd);
		if (final_path != NULL)
			return (final_path);
		i++;
	}
	return (NULL);
}

char	*find_the_right_path(char *cmd, char *env[])

{
	char	**all_path;
	char	*final_path;
	int		i;
	char	*full_path_check;

	all_path = NULL;
	final_path = NULL;
	i = 0;
	full_path_check = check_full_path(cmd);
	if (full_path_check != NULL)
		return (full_path_check);
	all_path = extract_paths(env);
	if (all_path == NULL)
		return (NULL);
	final_path = find_and_check_path(all_path, cmd);
	cleanup_paths(all_path);
	return (final_path);
}

void	execute(char *argv, char **envp)

{
	char	**cmd;
	int		i;
	char	*path;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = find_the_right_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		handle_error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
