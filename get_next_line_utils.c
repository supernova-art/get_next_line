/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:06:00 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/17 16:06:01 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    copy_line(t_list *list, char *line)
{
    int     i;
    int     k;

    k = 0;
    while(list)
    {
        i = 0;
        while(list->buffer[i])
        {
            if (list->buffer[i] == '\n')
            {
                line[k++] = '\n';
                line[k] = '\0';
                return ;
            }
            line[k++] = list->buffer[i++];
        }
        list = list -> next;
    }
    line[k] = '\0';
}

void dallocate(t_list **list, t_list *clean_node, char *buff)
{
    t_list *tmp;

    while(*list)
    {
        tmp = (*list)->next;
        free((*list)->buffer);
        free(*list);
        *list = tmp;
    }
    *list = NULL;
    if (clean_node->buffer[0])
        *list = clean_node;
    else
    {
        free(buff);
        free(clean_node);
    }
}

int     len_to_newline(t_list *list)
{
    int len;
    int i;
    
    if(!list)
        return (0);
    len = 0;
    while(list)
    {
        i = 0;
        while (list->buffer[i] && i < BUFFER_SIZE)
        {
            if(list->buffer[i] == '\n')
            {
                len++;
                return (len);
            }
            len++;
            i++;
        }
        list = list -> next;
    }
    return (len);
}

t_list *find_last_node(t_list *list)
{
    if (!list)
        return (NULL);
    while (list->next)
        list = list -> next;
    return (list);
}

int     found_new_line(t_list *list)
{
    int i;

    while (list)
    {
        i = 0;
        while (list->buffer[i] && i < BUFFER_SIZE)
        {
            if (list -> buffer[i] == '\n')
                return (1);
            i++;
        }
        list = list -> next;
    }
    return (0);
}
