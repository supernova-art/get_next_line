/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:43:31 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/18 10:29:17 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    cleanup_list(t_list **list)
{
    char *buff;
    int i;
    int k;
    t_list *last_node;
    t_list *clean_list;

    buff = malloc(BUFFER_SIZE + 1);
    clean_node (sizeof(t_list));
    if (!clean_node || !buff)
        return ;
    last_node = find_last_node(*list);
    i = 0;
    k = 0;
    while (last_node->buffer[i])
    {
        if (last_node->buffer[i] == '\n')
            break;
        i++;
    }
    while(last_node->buffer[i])
        buff[k++] = last_node->buffer[i++];
    buff[k] = '\0';
    clean_node -> buffer = buff;
    clean_node -> next = NULL;
}

char *get_line(t_list *list)
{
    char *next_line;
    int len;

    len = len_to_newline(list);
    next_line = malloc(len + 1);
    if (!next_line)
        return (NULL);
    copy_line(list, next_line);
    return (next_line);
}

void    linker(t_list *list, char *buff)
{
    t_list *new_node;
    t_list *last_node;

    last_node = find_last_node(*list);
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    if (!last_node)
        *list = new_node;
    else
        last_node -> next = new_node;
    new_node -> buffer = buff;
    new_node -> next = NULL;
}

void    creat_list(t_list **list, int fd)
{
    char *buff;
    int chars;

    while (!found_new_line(*list))
    {
        buff = malloc(BUFFER_SIZE + 1);
        if (!buff)
            return ;
        chars = read(fd, buff, BUFFER_SIZE);
        if (!chars)
        {
            free(buff);
            return ;
        }
        buff[chars] = '\0';
        linker(list, buff);
    }
}

char    *get_next_line(int fd)
{
    static t_list *list = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, str, BUFFER_SIZE) < 0)
        return (NULL);
    creat_list(&list, fd);
    line = get_line(list);
    cleanup_list(&list);
    return (line);
}
