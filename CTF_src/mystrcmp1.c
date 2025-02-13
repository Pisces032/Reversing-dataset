#include<stdio.h>
int strcmp(const char*s1, const char*s2)
{
    static int counter = 1;

    printf("%02d strcmp called!\n", counter++);
    
    while(*s1 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
    }

    return 0;
}