/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:15 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/17 11:11:35 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

//COMMAND PWD NO CHECK FOR INPUT ARGUMENTS

void ft_pwd(void)
{
	char buf[1024];
	char *ptr;

    ptr = getcwd(buf, 1024);
	if (!ptr)
	{
		perror("pwd ");
		exit(1);
	}
	printf("%s\n", ptr);
}

void checkchdir(char *str)
{
	if (chdir(str) != 0)
	{
		perror("cd ");
		exit(1);
	}
}

char	*setnewoldpwd(void)
{
	char buf[1024];
	char *ptr;

    ptr = getcwd(buf, 1024);
	if (!ptr)
	{
		perror("pwd ");
		exit(1);
	}
	return (ptr);
}

//COMMAND CD NO CHECK FOR INPUT ARGUMENTS
//COMMAND CD NO CHECK FOR TOO MANY ARGUMENTS

char	*ft_cd(char *str, char *oldpwd)
{
	char *newoldpwd = NULL;

	if ((str[0] == '~') || (!strcmp(str, "")))
	{
		newoldpwd = setnewoldpwd();
		checkchdir(getenv("HOME"));
		return(strdup(newoldpwd));
	}
	else if (str[0] == '-')
	{
		if (!oldpwd)
		{
			printf("cd: OLDPWD not set\n");
			exit(1);
		}
		newoldpwd = setnewoldpwd();
		checkchdir(oldpwd);
		return(strdup(newoldpwd));
	}
	else
	{
		newoldpwd = setnewoldpwd();
		checkchdir(str);
		return(strdup(newoldpwd));
	}
}

// MAIN FOR COMMAND CD AND COMMAND PWD CHECK

/* int main(void)
{
	char *str;
	char *oldpwd = NULL;

	str = readline("cd ");
	oldpwd = ft_cd(str, oldpwd);
	ft_pwd();
	while (str)
	{
		str = readline("cd ");
		oldpwd = ft_cd(str, oldpwd);
		ft_pwd();
	}
} */
