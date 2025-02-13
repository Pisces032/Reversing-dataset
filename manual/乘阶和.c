#include<stdio.h>
int main()
{
int N,i=1,S=1,Z=0,t;
scanf("%d\n",&N);
int cheng(int x,int y);
while(i<=N)
{
	Z=cheng(t,i)+Z;
		i=i+1;
}
return 0;
}
int cheng(int x=1,int y)
{
int n;
while(x<=y)
{
n=n*x;
	x=x+1;
}
return (n);
}

