#include <stdio.h>

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    const unsigned char *p1 = ptr1;
    const unsigned char *p2 = ptr2;
    printf("memcmp called!\n");
    printf("%s\n%s\n", ptr1, ptr2);
    for (size_t i = 0; i < num; ++i) {
        if (p1[i] != p2[i]) {
            return p1[i] - p2[i];
        }
    }
    
    return 0;
}