/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:12:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/05/21 14:46:37 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

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
    en->next = NULL;
    return(en);
}

t_shenv *ft_lstlast(t_shenv *en)
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
        last = ft_lstlast(*en);
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

void ft_env(t_shenv *en)
{
    while(en)
    {
        printf("%s=", en->key);
        printf("%s\n", en->value);
        en = en->next;
    }
}

int main(int gc, char **gv, char **env)
{
    (void)gc;
    (void)gv;
    t_shenv *en = NULL;

    en = initshellenv(en, env);
    ft_env(en);
}