/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:43:31 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/17 15:43:33 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



void    append(t_list **list, char *buff)
{
    t_list *new_node;
    t_list *last_node;

    last_node = find_last_node(*list);
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    if (last_node == NULL) 
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
        append(list, buff);
    }
}

char *get_next_line(int fd)
{
    static t_list *list;
    char    *next_line;

    if (fd < 0 || BUFFER_SIZE == 0 || read(fd, next_line, 0)< 0)
        return (NULL);
    creat_list(&list, fd);
    if (list)
}
