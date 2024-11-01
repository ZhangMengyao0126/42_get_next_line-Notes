#include "get_next_line.h"

ft_free(void **str)
{
    free(*str);
    *str = NULL;
    return(NULL);
}


char *ft_strchr(const unsigned char *s, int c)
//ft_strchr: String character, searches for the first occurrence of a character 'c' in a string 's'.

//const char *: 
//1. Constant character *, meaning the data being pointed to cannot be modified through this pointer.
//2. Safety: Marking a pointer as const char* tells the compiler and other developers that this data should not be modified. 
//////////// It prevents accidental changes to data that should be immutable, such as a constant string or shared resource.
//////////// Const char* is commonly used when the function only needs to read a string.

//Why use "int c" instead of "char c":
//1. Compatibility with Extended ASCII(0-255) and EOF(-1): 
/////If c were a char, there would be no way to distinguish between the EOF value -1 and the valid character 255.
//2. Compatibility and consistency with the C standard library:
/////According to the C standard, characters passed to standard library functions are promoted to int.
{
    size_t i;

    i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == (unsigned char)c)
        //(unsigned char): To keep the value type in the comparition consistent.
            return((char *)s + i);
            //(char *): To keep the return value type consistent
            //s + i: Pointer arithmetic, move the pointer to the position we want.
        i++;
    }
    return(NULL);
}

