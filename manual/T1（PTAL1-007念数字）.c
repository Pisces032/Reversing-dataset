#include<stdio.h>
int main()
{
	char a[1000]={0},c;
	int i=0,j,f;
	while((c=getchar())!='\n')
	{
		a[i]=c;
		i++;
	}
	f=i-1;
	for(j=0;j<i;j++)
	{
		if(a[j]=='-')
			if(j==f)printf("fu");
			else printf("fu ");
		if(a[j]=='0')
			if(j==f)printf("ling");
			else printf("ling ");
		if(a[j]=='1')
			if(j==f)printf("yi");
			else printf("yi ");
		if(a[j]=='2')
			if(j==f)printf("er");
			else printf("er ");
		if(a[j]=='3')
			if(j==f)printf("san");
			else printf("san ");
		if(a[j]=='4')
			if(j==f)printf("si");
			else printf("si ");
		if(a[j]=='5')
			if(j==f)printf("wu");
			else printf("wu ");
		if(a[j]=='6')
			if(j==f)printf("liu");
			else printf("liu ");
		if(a[j]=='7')
			if(j==f)printf("qi");
			else printf("qi ");
		if(a[j]=='8')
			if(j==f)printf("ba");
			else printf("ba ");
		if(a[j]=='9')
			if(j==f)printf("jiu");
			else printf("jiu ");
	}
	return 0;
}
