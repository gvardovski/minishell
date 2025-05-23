/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:12:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/23 13:37:44 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void freeenv(t_shenv *en)
{
	t_shenv *next;

	if (en)
	{
		while(en)
		{
			next = en->next;
			free(en->key);
			free(en->value);
			free(en);
			en = next;
		}
	}
}

int getposeql(char *str)
{
    int i;

    i = 0;
    while(str[i] != '=')
        i++;
    return(i);
}

t_shenv *new(char *key, char *value)
{
    t_shenv *en;

    en = malloc(sizeof(t_shenv));
    en->key = key;
    en->value = value;
	en->export = 0;
    en->next = NULL;
    return(en);
}

t_shenv *lstlast(t_shenv *en)
{
    if (!en)
        return(NULL);
    while(en->next != NULL)
        en = en->next;
    return(en);
}

void addback(t_shenv **en, t_shenv *new)
{
    t_shenv *last;

    if (!new)
       return ;
    if (*en)
    {
    	last = lstlast(*en);
        last->next = new;
    }
   	else
    	*en = new;
}

t_shenv *initshellenv(t_shenv *en, char **env)
{
    int i;
    int pos;
    char *key;
    char *value;

    i = 0;
    while(env[i])
    {
        pos = getposeql(env[i]);
        key = ft_substr(env[i], 0, pos);
        value = ft_substr(env[i], pos + 1, ft_strlen(env[i]) - pos - 1);
        addback(&en, new(key, value));
        i++;
    }
    return(en);
}

int	ft_env(t_shenv *en, char **gv)
{
	if (arr_len(gv) > 1)
	{
		printf("env: ‘%s’: No such file or directory\n", gv[1]);
		return (1);
	}
	if (ft_strlen(gv[0]) > 3)
	{
		printf("‘%s’: command not found\n", gv[0]);
		return (1);
	}
    while(en)
    {
		if (en->export == 0)
        	ft_printf("%s=%s\n", en->key, en->value);
		en = en->next;
    }
	return (0);
}

/* int main(int gc, char **gv, char **env)
{
    (void)gc;
    (void)gv;
	char *gv1[2];
    t_shenv *en = NULL;
	
	gv1[0] = "env";
	gv1[1] = NULL;
    en = initshellenv(en, env);
	char *gv2[3];
	gv2[0] = "unset";
	gv2[1] = "SHELL";
	gv2[2] = NULL;
	ft_unset(&en, gv2);
    ft_env(en, gv1);
	freeenv(en);
} */