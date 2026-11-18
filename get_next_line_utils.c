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

int     found_newline(t_list *list)
{
    int i;

    if (!list)
        return (0);
    while(list)
    {
        i = 0;
        while(list -> buffer[i])
        {
            if (list->buffer[i] == '\n')
                return (1);
            i++;
        }
        list = list -> next;
    }
    return (0);
}

t_list *find_last_node(t_list *list)
{
    if (!list)
        return NULL;
    while (list->next)
    {
        list = list -> next;
    }
    return (list);
}

int main(void)
{
    t_list *list = malloc(sizeof(t_list));
    if (!list)
        return -1;
    list -> buffer = "hello tester0";
    list -> next  = NULL;

    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return -1;
    node -> buffer = "hello tester1";
    node -> next  = NULL;

    t_list *inode = malloc(sizeof(t_list));
    if (!inode)
        return -1;
    inode -> buffer = "hello tester2";
    inode -> next  = NULL;

    list -> next = node;
    node -> next = inode;

    t_list *last = find_last_node(list);
    printf("%s\n", (char *)last->buffer);
}
