#include <stdio.h>
#include <string.h>
int main()
{
	char s[10000];int i,g=0,p=0,l=0,t=0;
	gets(s);
	for (i=0;i<strlen(s);i++){
		if (s[i]=='g'||s[i]=='G')g++;
		else if (s[i]=='l'||s[i]=='L')l++;
		else if (s[i]=='p'||s[i]=='P')p++;
		else if (s[i]=='t'||s[i]=='T')t++;
	}
	while (g!=0||l!=0||p!=0||t!=0){
		if (g!=0){printf("G");g--;};
		if (p!=0){printf("P");p--;};
		if (l!=0){printf("L");l--;};
		if (t!=0){printf("T");t--;};
	}
	return 0;
}
