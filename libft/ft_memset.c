#include "includes/libft.h"
// memset have to trust the length that is passed in. 
// memset needs to work on a general piece of memory, 
// not just a 0 terminated string - so there should not be such a check.



void    *ft_memset(void *b, int c, int len)
{
    int i;
    unsigned char   *p = b;

    i = 0;
    while(len > 0)
        p[--len] = c;
    return(b);
}