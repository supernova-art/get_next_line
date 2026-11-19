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

t_list *find_last_node(t_list *list)
{
    if (!list)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}

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
                break;
            }
            count++;
            i++;
        }
        list = list -> next;
    }
    return (count);
}

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
                break;
            }
            line[k++] = list->content[i++];
        }
        list = list->next;
    }
    line[k] = '\0';
}

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
