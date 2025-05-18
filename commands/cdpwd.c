/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdpwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:15 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/18 22:25:41 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//HANDLE EXITS

//IT DOESNT MATTER WHAT WOULD BE AFTER PWD COMMAND >> IT WILL PRINT PWD

void ft_pwd(t_list *ptr)
{
	char buf[1024];
	char *p;

    p = getcwd(buf, 1024);
	if (!p)
	{
		perror("pwd");
		exit(1);
	}
	ptr->pwd = p;
	printf("%s\n", ptr->pwd);
}

void checkchdir(char *str)
{
	if (chdir(str) != 0)
	{ 
		perror("cd");
		free(str);
		exit(1);
	}
}


char *handlearg(char *str)
{
	char *strtrim;
	char *tmp = NULL;

	strtrim = ft_strtrim(str, " ");
	if ((strtrim[0] == 39) && (strtrim[strlen(strtrim) - 1] == 39))
	{
		tmp = ft_strtrim(strtrim, "'");
		free(strtrim);
		return(tmp);
	}
	if ((strtrim[0] == 34) && (strtrim[strlen(strtrim) - 1] == 34))
	{
		tmp = ft_strtrim(strtrim, "\"");
		free(strtrim);
		return(tmp);
	}
	return(strtrim);
}

void getnewoldpwd(t_list *ptr, char *str, int mes)
{
	ptr->oldpwd = ptr->pwd;
	checkchdir(str);
	if (mes == 1)
		ft_pwd(ptr);
}

//COMMAND CD NO CHECK FOR TOO MANY ARGUMENTS, BUT IT WILL BE EXIT WITH ERROR "NO SUCH DIRECTOTY"
//FIRST SPACE PROBLEM.

void	ft_cd(t_list *ptr)
{
	char *strtrim;
	char buf[1024];
	
	if (!ptr->pwd)
		ptr->pwd = getcwd(buf, 1024);
	printf("%s\n", ptr->pwd);
	if (ptr->oldpwd)
		printf("%s\n", ptr->oldpwd);
	strtrim = handlearg(ptr->str);
	if ((!strcmp(ptr->str, "~")) || (!strcmp(ptr->str, "")))
		getnewoldpwd(ptr, getenv("HOME"), 0);
	else if ((!strcmp(ptr->str, "-")))
	{
		if (!ptr->oldpwd)
		{
			printf("cd: OLDPWD not set\n");
			free(strtrim);
			exit(1);
		}
		getnewoldpwd(ptr, ptr->oldpwd,1);
	}
	else
		getnewoldpwd(ptr, strtrim, 0);
	free(strtrim);
}

// MAIN FOR COMMAND CD AND COMMAND PWD CHECK

int main(void)
{	
	t_list *ptr;

	ptr = malloc(sizeof(t_list));
	ptr->oldpwd = NULL;
	ptr->pwd = NULL;

	ptr->str = readline("cd");
	ft_cd(ptr);
	ft_pwd(ptr);
	while (ptr->str)
	{
		ptr->str = readline("cd");
		ft_cd(ptr);
		ft_pwd(ptr);
	}
}

/* int main(void)
{
	t_list *ptr;

	ptr = malloc(sizeof(t_list));
	ptr->oldpwd = NULL;

	ptr->str = readline("cd");
	ft_cd(ptr);
	ft_pwd();
	ptr->str = readline("cd");
	ft_cd(ptr);
	ft_pwd();
	free(ptr->oldpwd);
	if (ptr->str)
		free(ptr->str);
	free(ptr);
} */

// MAIN FOR COMMAND PWD CHECK

/* int main(void)
{
	ft_pwd();
} */