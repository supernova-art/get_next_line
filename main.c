


#include "get_next_line.h"

int main(void)
{
    char *line; 
    int fd = open("text.t", O_RDWR | O_CREAT);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    while (line)
    {  
        printf("%s", line);
        line = get_next_line(fd);
    }
    free(line);
}
