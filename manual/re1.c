#include "stdio.h"

int main(){
	char flag[]="{34sy_r3v3rs3}";
	int i;
	for(i=0; flag[i]!='\0'; i++){
		if(flag[i] == '3')
			flag[i] = 'e';
		if(flag[i] == '4')
			flag[i] = 'a';
	}
	printf("%s", flag);
	return 0;
}
