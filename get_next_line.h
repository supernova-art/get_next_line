/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:28:22 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/18 18:28:23 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL
#define GNL

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

typedef struct s_list {
    char *content;
    struct s_list *next;
}               t_list;

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char    *get_line(t_list *list);
void    append_node(t_list **list, char *buff);
void    read_and_stash(t_list **list, int fd);
t_list  *find_last_node(t_list *list);
int     len_to_newline(t_list *list);
void    copy_content(t_list *list, char *line);
int     found_newline(t_list *list);


#endif
