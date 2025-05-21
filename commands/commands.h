/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:44 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/21 13:57:45 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

typedef struct s_list
{
	char *str;
    char *pwd;
	char *oldpwd;
}	t_list;

typedef struct s_shenv
{
	char *key;
    char *value;
	struct s_shenv *next;
}	t_shenv;

# define _POSIX_C_SOURCE 200809L

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

void	ft_cd(t_list *ptr);
void    ft_pwd(t_list *ptr);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

#endif