/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:44 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/16 16:06:57 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

#define _POSIX_C_SOURCE 200809L

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <dirent.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

void	ft_cd(char *gv);
void	ft_pwd(void);

#endif