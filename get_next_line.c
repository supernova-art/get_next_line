/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:28:08 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/18 18:28:13 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_line(t_list *list)
{
    char *line;
    int len;

    len = len_to_newline(list);
    line = malloc(len + 1);
    if (!line)
        return (NULL);
    copy_content(list, line);
    return (line);
}

void    append_node(t_list **list, char *buff)
{
    t_list *new_node;
    t_list *last_node;

    last_node =  find_last_node(*list);
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    if (!last_node)
        *list = new_node;
    else
        last_node -> next = new_node;
    new_node->content = buff;
    new_node->next = NULL;
}

void    read_and_stash(t_list **list, int fd)
{
    char *buff;
    int chars;

    while (!found_newline(*list))
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
        append_node(list, buff);
    }
}

char    *get_next_line(int fd)
{
    static t_list *list;
    char *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0)//to improve
        return (NULL);
    read_and_stash(&list, fd);
    if (!list)
        return (NULL);
    next_line = get_line(list);
    return (next_line);
}
