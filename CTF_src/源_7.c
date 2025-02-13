#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	unsigned char opcode[] =
	{
	  0x70, 0x00, 0x00, 0x00, 0x1E, 0x71, 0x30, 0x73, 0x00, 0x7A,
	  0x73, 0x10, 0x67, 0x01, 0x7B, 0x74, 0x00, 0x7A, 0x75, 0x0B,
	  0x70, 0x00, 0x00, 0x00, 0x1E, 0x71, 0x30, 0x7B, 0x75, 0x01,
	  0x70, 0x00, 0x00, 0x00, 0x1E, 0x71, 0x30, 0x73, 0x10, 0x7A,
	  0x73, 0x00, 0x6D, 0x01, 0x74, 0x00, 0x75, 0x09, 0x66
	};
	for (int i = 0; i < 49; i++)
	{
        if ((opcode[i] >= 0x66 && opcode[i] <= 0x7C) && (opcode[i - 1] >= 0x66 && opcode[i - 1] <= 0x7C))
        {
            printf("\n");
        }
		switch (opcode[i])
		{
        case 0x66:
            printf("nop  ");
            continue;
        case 0x67:
            printf("add  ");
            continue;
        case 0x68:
            printf("sub  ");
            continue;
        case 0x69:
            printf("mul  ");
            continue;
        case 0x6A:
            printf("div  ");
            continue;
        case 0x6B:
            printf("inc  ");
            continue;
        case 0x6C:
            printf("dec  ");
            continue;
        case 0x6D:
            printf("xor  ");
            continue;
        case 0x6E:
            printf("and  ");
            continue;
        case 0x6F:
            printf("push  ");
            continue;
        case 0x70:
            printf("pushd  ");
            continue;
        case 0x71:
            printf("pop  ");
            continue;
        case 0x72:
            printf("mov  ");
            continue;
        case 0x73:
            printf("movd  ");
            continue;
        case 0x74:
            printf("move2d  ");
            continue;
        case 0x75:
            printf("loop  ");
            continue;
        case 0x76:
            printf("cmp  ");
            continue;
        case 0x77:
            printf("jl  ");
            continue;
        case 0x78:
            printf("jg  ");
            continue;
        case 0x79:
            printf("jz  ");
            continue;
        case 0x7A:
            printf("incd  ");
            continue;
        case 0x7B:
            printf("decd  ");
            continue;
        case 0x7C:
            printf("xor_ops  ");
            continue;
        default:
            if (opcode[i + 1] >= 0x66 && opcode[i + 1] <= 0x7C)
            {

                printf("%#x\n", opcode[i]);
            }
            else 
            {
                printf("%#x, ", opcode[i]);
            }
            continue;
		}
	}
    return 0;
}
/*
pushd  0, 0, 0, 0x1e
pop  0x30
movd  0
incd
movd  0x10
add  0x1
decd
move2d  0
incd
loop  0xb
pushd  0, 0, 0, 0x1e
pop  0x30
decd
loop  0x1
pushd  0, 0, 0, 0x1e
pop  0x30
movd  0x10
incd
movd  0
xor  0x1
move2d  0
loop  0x9
nop
*/