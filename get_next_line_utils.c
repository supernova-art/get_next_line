/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:28:31 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/18 18:28:37 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//to find the last node in the list
t_list *find_last_node(t_list *list)
{
    if (!list)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}

//to calculate the len of the leftover
int     len_to_newline(t_list *list)
{
    int count;
    int i;

    count = 0;
    while (list)
    {
        i = 0;
        while(list->content[i])
        {
            if (list->content[i] == '\n')
            {
                count++;
                return (count);
            }
            count++;
            i++;
        }
        list = list -> next;
    }
    return (count);
}

//to copy the line from the list
void    copy_content(t_list *list, char *line)
{
    int i;
    int k;

    k = 0;
    while (list)
    {
        i = 0;
        while(list->content[i])
        {
            if (list->content[i] == '\n')
            {
                line[k++] = '\n';
                line[k] = '\0';
                return ;
            }
            line[k++] = list->content[i++];
        }
        list = list->next;
    }
    line[k] = '\0';
}

//fct that checks whether a newline exist or not
int     found_newline(t_list *list)
{
    int     i;

    while (list)
    {
        i = 0;
        while(list->content[i] && i < BUFFER_SIZE)
        {
            if (list->content[i] == '\n')
                return (1);
            i++;
        }
        list = list -> next;
    }
    return (0);
}

//fct that free all the list and avoid our program to have some memory leak issues
void    free_all(t_list **list, t_list *clean_node, char *buff)
{
    t_list *tmp;

    while (*list)
    {
        tmp = (*list)->next;
        free((*list)->content);
        free(*list);
        *list = tmp;
    }
    *list = NULL;
    if (clean_node->content[0])
        *list = clean_node;
    else
    {
        free(buff);
        free(clean_node);
    }
}
