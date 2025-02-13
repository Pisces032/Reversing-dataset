#include<stdio.h>
int strcmp(const char*s1, const char*s2)
{
    printf("strcmp clled!");
    
    while(*s1 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
    }

    return *s1 - *s2;
}