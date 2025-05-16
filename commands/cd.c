/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:20:15 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/16 16:12:21 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

/* void	handler(int sig)
{
	static int	cnt = 0;
	static int	sum = 0;

	if (sig == SIGUSR1)
		sum = sum + 0;
	else if (sig == SIGUSR2)
		sum = sum + (1 * ft_rpower(2, 7 - cnt));
	cnt++;
	if (cnt == 8)
	{
		write (1, &sum, 1);
		if (sum == 0)
			ft_printf("\n");
		cnt = 0;
		sum = 0;
	}
} */

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

void checkchdir(char *gv)
{
	if (chdir(gv) != 0)
	{
		perror("cd ");
		exit(1);
	}
}

void	ft_cd(char *gv)
{
	if ((gv[0] == '~') || (!strcmp(gv, "")))
	{
		gv = getenv("HOME");
		checkchdir(gv);
	}
	/* else if (gc > 2)
	{
		printf("cd: too many arguments\n");
		exit(0);
	} */
	else if (gv[0] == '-')
	{
		gv = getenv("OLDPWD");
		checkchdir(gv);
	}
	else
		checkchdir(gv);
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

/* int main(int gc, char **gv)
{
	printf ("long %lu\n", strlen(gv[1]));
	printf ("Path %s\n", gv[1]);
	printf ("fucking tilda %d %d", gv[1][0], gv[1][1]);
	ft_cd(gc, gv[1]);
	ft_pwd();
} */
