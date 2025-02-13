#include <stdio.h>

char key[] = {0x62, 0x6f, 0x6d, 0x62};

void xteade(unsigned int *v1, unsigned int *v2){
    // printf("0x%x", 0x90508D47 - 0x77BF7F99*4*33);
    unsigned int delta = 0xd192c263;

    for (int i = 0; i < 4; i ++){
        for (int j = 0; j < 33; j ++){
            delta += 0x77BF7F99;
            *v2 -= (((32 * *v1) ^ (*v1 >> 4)) + *v1) ^ (delta + key[(delta >> 11) & 3]);
            *v1 -= (((32 * *v2) ^ (*v2 >> 4)) + *v2) ^ (delta + key[delta & 3]) ^ delta;
        }
    }
}

int main(){
    unsigned char ida_chars[] =
    {
    0xE0, 0xF2, 0x23, 0x95, 0x93, 0xC2, 0xD8, 0x8E, 0x93, 0xC3, 
    0x68, 0x86, 0xBC, 0x50, 0xF2, 0xDD, 0x99, 0x44, 0x0E, 0x51, 
    0x44, 0xBD, 0x60, 0x8C, 0xF2, 0xAB, 0xDC, 0x34, 0x60, 0xD2, 
    0x0F, 0xC1
    };

    for (int i = 0; i < 4; i ++){
        xteade((unsigned int *)(ida_chars + 8*i), (unsigned int *)(ida_chars + 4 + 8*i));
    }
    printf("%s\n", (char *)ida_chars);
    
    return 0;
}