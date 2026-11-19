


#include "get_next_line.h"

int main(void)
{
    int fd = open("text.t", O_RDWR | O_CREAT);
    if (fd < 0)
        return (-1);
    char *line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
}
