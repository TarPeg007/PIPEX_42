/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfunction2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfellahi <sfellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:36:00 by sfellahi          #+#    #+#             */
/*   Updated: 2024/05/23 20:19:15 by sfellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)

{
	size_t	i;
	size_t	j;

	if (len == 0 && n[0])
		return (NULL);
	if (!n[0])
		return ((char *)h);
	i = -1;
	while (++i < len && h[i])
	{
		j = -1;
		while (n[++j] && i + j < len)
		{
			if (n[j] != h[i + j])
				break ;
		}
		if (!n[j])
			return ((char *)(h + i));
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)

{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static size_t	strlenbysaad(const char *s)

{
	size_t	j;

	j = 0;
	while (*(s + j) != '\0')
	{
		j++;
	}
	return (j);
}

static char	*str_new(size_t n)

{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)

{
	char	*str;
	char	*str_ptr;

	if (!s1 || !s2)
		return (NULL);
	str = str_new(strlenbysaad(s1) + strlenbysaad(s2));
	if (!str)
		return (NULL);
	str_ptr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str_ptr);
}
