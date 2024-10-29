#include "get_next_line.h"

static char *ft_get_buffer(int fd, char *buffer)
{
    
}

static char *ft_get_one_line(char *buffer)

static char *ft_to_nextline(char *buffer)

char *get_next_line(int fd)
{
    char *oneline;
    static char *buffer;
    //Static Variables: A variable declared as static inside a function maintains its value between function calls. 
    if（fd < 0 || BUFFER_SIZE <= 0）
        return(NULL);
    //Error: Invalid file descriptor or buffer size.
    buffer = ft_get_buffer(fd, buffer);
    //First step: Set the buffer, and read data(including our target line) from the file descriptor and adds it to buffer.
    if (!buffer)
        return(NULL);
    //Error: Fail to set the buffer————the return value of ft_get_buffer is NULL.
    oneline = ft_get_one_line(buffer);
    //Second step: Extract the target line from the buffer as the return value.
    if (!oneline)
        return(ft_free(&buffer)) 
    //Error: Fail to extract the line————the return value of ft_get_one_line is NULL.
    //Memory-Free: Free the buffer we set earlier.
    buffer = ft_to_nextline(buffer);
    //Third step: Move the buffer pointer to the start of the next line in buffer.
    return(oneline);
}
