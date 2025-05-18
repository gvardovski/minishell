/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 09:17:17 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/18 10:52:16 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

//ECHO [OPTION] [STRING]

void readprintdir(char *str)
{
    DIR *dir;
    struct dirent *dirs;
    dir = opendir(str);
    if(dir != NULL)
    {
        while((dirs=readdir(dir))!= NULL)
        {
            if ((strcmp(dirs->d_name,".")) && (strcmp(dirs->d_name,"..")))
                printf("%s ", dirs->d_name);
        }
    }
    else
        printf("echo : Cannot open directory %s\n", str);
    closedir(dir);
}

char	*getpwd(void)
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

void ft_echo(char *str, char *flag)
{
    if (!flag)
        printf("%s\n", str);
    else if (strcmp(flag,"-n") == 0)
        printf("%s", str);
    else if (strcmp(flag,"*") == 0)
    {
        printf("%s ", str);
        readprintdir(getpwd());
        printf("\n");
    }
}

int main(int gc, char **gv)
{
    char *flag = NULL;

    if (gc == 1)
        ft_echo("", flag);
	else if (gc == 2)
        ft_echo(gv[1], flag);
    else
        ft_echo(gv[1], gv[2]);
}