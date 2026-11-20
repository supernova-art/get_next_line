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
//to  clean the list for the next call
void    polish_list(t_list **list)
{
    t_list *last_node;
    t_list *clean_node;
    int i;
    int j;
    char *buff;

    i = 0;
    j = 0;
    buff = malloc(BUFFER_SIZE + 1);
    clean_node = malloc(sizeof(t_list));
    if (!buff || !clean_node)
        return ;// to inquire abt
    last_node = find_last_node(*list);
    while (last_node->content[i] && last_node->content[i] != '\n')
        i++;
    while (last_node->content[i] && last_node->content[++i])
        buff[j++] = last_node->content[i];
    buff[j] = '\0';
    clean_node->content = buff;
    clean_node->next = NULL;
    /*all the previous nodes must be freed*/
    free_all(list, clean_node, buff);
}

//to get the line from the list (up to \n)
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

//to append the buff to the node
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

//to read the file into a buff in order to append it to a list 
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
        if (chars <= 0)
        {
            free(buff);
            return ;
        }
        buff[chars] = '\0';
        append_node(list, buff);
    }
}

//mother function
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
    polish_list(&list);
    return (next_line);
}
