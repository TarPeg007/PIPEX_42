/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfellahi <sfellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:32:50 by sfellahi          #+#    #+#             */
/*   Updated: 2024/05/25 09:58:09 by sfellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strnstr(const char *h, const char *n, size_t len);
char		*ft_strdup(const char *s1);
char		**extract_paths(char *environment[]);
char		*check_full_path(char *command);
char		*check_and_build_path(char *path, char *command);
size_t		ft_strlen(const char *s);
int			ft_strcmp(char *s1, char *s2);
char		*find_and_check_path(char **all_path, char *cmd);
char		*find_the_right_path(char *cmd, char *env[]);
void		cleanup_paths(char **paths);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
void		handle_error(void);
void		execute(char *argv, char **envp);
char		*ft_strchr(const char *str, int c);

#endif
