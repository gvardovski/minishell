/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 09:17:17 by svolkau           #+#    #+#             */
/*   Updated: 2025/06/04 22:11:51 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void readprintdir(char *str)
{
    DIR *dir;
    struct dirent *dirs;
	
    dir = opendir(str);
    if(dir != NULL)
    {
        while((dirs = readdir(dir)) != NULL)
        {
            if ((ft_strncmp(".", dirs->d_name, ft_strlen(dirs->d_name)) != 0) 
			&& (ft_strncmp("..", dirs->d_name, ft_strlen(dirs->d_name)) != 0))
            	ft_printf("%s ", dirs->d_name);
        }
    }
    else
        ft_printf("minishell: echo: Cannot open directory '%s'\n", str);
    closedir(dir);
}

char *cwd()
{
	char buf[1024];
	char *p;
	
    p = getcwd(buf, 1024);
	if (!p)
	{
		perror("minishell: pwd");
		return (NULL);
	}
	return(ft_strdup(p));
}

char *trimall(char *str)
{
	if (str[0] == '\'')
		return(ft_strtrim(str,"'"));
	if (str[0] == '\"')
		return(ft_strtrim(str,"\""));
	if (str[0] == ' ')
		return(ft_strtrim(str," "));
	return(str);
}

void print_arr(char **gv, int start, int mes)
{
	int i;
	int len;
	char *str;
	char *trimstr;

	i = start;
	while(gv[i])
	{
		if ((i == start) && (ft_strncmp(" ", gv[i], ft_strlen(gv[i])) == 0))
			i++;
		trimstr = trimall(gv[i]);
		len = ft_strlen(trimstr);
		if (len == 0)
			len += 1;
		if (ft_strncmp("*", trimstr, len) == 0)
		{
			str = cwd();
			readprintdir(str);
			free(str);
		}
		else
			ft_printf("%s", trimstr);
		if ((ft_strlen(trimstr) != 0) && (ft_strncmp("*", trimstr, len) != 0) && gv[i + 1])
			ft_printf(" "); 
		free(trimstr);
		i++;
	}
	if (mes == 0)
		ft_printf("\n");
}

int ft_echo(t_main_dat *main_data, char **gv)
{
	t_main_dat temp;
	int i;
	int len;
	char *trimstr;
	
	temp = *main_data;
	(void)temp;
	i = 0;
	while(gv[i])
	{
		ft_printf("%d |%s|\n", i, gv[i]);
		i++;
	}
	if (ft_strlen(gv[0]) > 4)
	{
		ft_printf("minishell: '%s': command not found\n", gv[0]);
		return(1);	
	}
    if (arr_len(gv) == 1)
	{
		ft_printf("\n");
		return(0);
	}
	/* i = 1;
	while (ft_strncmp(" ", gv[i], ft_strlen(gv[i])) == 0) 
		i++;
	ft_printf("%d\n", i);
	trimstr = trimall(gv[i]);
	len = ft_strlen(trimstr);
	if (len == 0)
		len += 1;
   	if ((ft_strncmp("-n", trimstr, len) == 0) && ((arr_len(gv) - 1) == i))
	   	ft_printf("");
	if (ft_strncmp("-n", trimstr, len) == 0)
	   	print_arr(gv, i + 1, 1);
	if (ft_strncmp("-n", trimstr, len) != 0)
		print_arr(gv, 1, 0);
	free(trimstr); */
	return(0);
}
