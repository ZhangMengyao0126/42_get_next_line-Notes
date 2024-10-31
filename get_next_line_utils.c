#include "get_next_line.h"

ft_free(void **str)
{
    free(*str);
    *str = NULL;
    return(NULL);
}

