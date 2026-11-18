/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:44:58 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/17 15:44:59 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL
# define GNL

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

typedef struct s_list {
    char *buffer;
    struct s_list *next;
}       t_list;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char    *get_next_line(int fd);
void    linker(t_list *list, char *buff);
void    creat_list(t_list **list, int fd);
char    *get_line(t_list *list);
void    cleanup_list(t_list **list);
void    copy_line(t_list *list, char *line);
void    dallocate(t_list **list, t_list *node, char *buff);
int     len_to_newline(t_list *list);
t_list  *find_last_node(t_list *list);
int     found_new_line(t_list *list);

#endif
