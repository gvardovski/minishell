/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:44 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/23 14:09:05 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

typedef struct s_shenv
{
	char *key;
    char *value;
	int	export;
	struct s_shenv *next;
}	t_shenv;

# include <dirent.h>

int	ft_cd( t_shenv *en, char **gv);
int	ft_pwd();
int ft_echo(char **gv);
int	ft_env(t_shenv *en, char **gv);
void delone(t_shenv **en, char *key);
t_shenv *initshellenv(t_shenv *en, char **env);
void freeenv(t_shenv *en);
int ft_unset(t_shenv **en, char **gv);
int getposeql(char *str);

#endif