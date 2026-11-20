


#include "get_next_line.h"

int main(void)
{
    char *line; 
    int fd = open("text.t", O_RDWR | O_CREAT);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)))
    {  
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
