/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:44 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/17 11:02:56 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# define _POSIX_C_SOURCE 200809L

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

char    *ft_cd(char *str, char *oldpwd);
void	ft_pwd(void);

#endif