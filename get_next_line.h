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

char    *get_next_line(int fd);

#endif
