/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:15 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/17 09:26:56 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

void ft_printpwd(void)
{
	char buf[1024];
	char *ptr;

    ptr = getcwd(buf, 1024);
	if (!ptr)
		perror("pwd ");
	else
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

void	ft_cd(char *str)
{
	if ((str[0] == '~') || (!strcmp(str, "")))
	{
		str = getenv("HOME");
		checkchdir(str);
	}
	/* else if (gc > 2)
	{
		printf("cd: too many arguments\n");
		exit(0);
	} */
	else if (str[0] == '-')
	{
		str = getenv("OLDPWD");
		checkchdir(str);
	}
	else
		checkchdir(str);
}

int main(void)
{
	char *str;

	str = readline("cd ");
	ft_cd(str);
	ft_printpwd();
	while (str)
	{
		str = readline("cd ");
		ft_cd(str);
		ft_printpwd();
	}
}

