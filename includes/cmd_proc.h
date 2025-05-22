/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_proc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:47:23 by aobshatk          #+#    #+#             */
/*   Updated: 2025/05/19 13:36:01 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_PROC_H
# define CMD_PROC_H

# include "../libft/ft_printf/libftprintf.h"
# include "../libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include <wait.h>

typedef struct s_charset
{
	int					*count;
	char				chr;
	struct s_charset	*next;
}						t_charset;

typedef struct s_redir
{
	int				redir_in;
	int				redir_out;
}						t_redir;

typedef struct s_args
{
	char				*arg;
	struct s_args		*next;
}						t_args;

typedef struct s_commands
{
	char				*path;
	char				**argv;
	struct s_commands	*next;
}						t_commands;

typedef struct s_seq
{
	int					pipe;
	t_redir				redir_fds;
	t_commands			*commands;
}						t_seq;

void					add_sequence(t_seq **sequence);
void					clear_sequence(t_seq **sequence);
void					clear_charset(t_charset **set);
void					add_charset(t_charset **set, t_charset *new_set);
void					clear_charset(t_charset **set);
void					update_list(t_args **args, char *arg);
void					ext_qt(char **arg, char **res, int *i);
void					del_a(char *argument);
void					add_node_a(t_args **lst, t_args *new);
void					clear_list_a(t_args **lst, void (*del_a)(char *));
void					delete_node_a(t_args *lst, void (*del_a)(char *));
t_charset				*extract_string(char *str, char *delim_set);
t_charset				*new_charset(char c);
t_args					*create_node_a(char *argument);
char					**split_arguments(char *arguments);
char					**create_argv(t_args **args);

#endif
