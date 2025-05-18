/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:06:43 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/18 20:40:53 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static char	*ft_strcpy(char *dstr, const char *str)
{
	while (*str)
		*dstr++ = *str++;
	*dstr = '\0';
	return (dstr);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*dstr;

    if (str)
    {
        return (NULL);
    }
	dstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if(!dstr)
		return (NULL);
	ft_strcpy(dstr, str);
	return (dstr);
}


static int	ft_chset(const char c, const char *set)
{
    int i;

    i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	st;
	int	fin;

	if (!s1)
		return (NULL);
	st = 0;
	while (ft_chset(s1[st], set) == 1)
		st++;
	fin = (ft_strlen(s1) - 1);
	while (ft_chset(s1[fin], set) == 1)
		fin--;
	return (ft_substr(s1, st, fin - st + 1));
}