//最佳情侣身高差
//#include<stdio.h>
//void main()
//{
//	int n,i;
//	double h[10],c[10];
//	char g;
//	scanf("%d",&n);
//	scanf("%c%lf",&g,&h[0]);
//	for(i=0;i<n;i++)
//	{
//		if(g=='F')
//			c[i]=h[i]*1.09;
//		if(g=='M')
//			c[i]=h[i]/1.09;
//		scanf("%c%lf",&g,&h[i]);
//	}
//	for(i=0;i<n;i++)
//		printf("%.2f\n",c[i]);
//}
//有问题的程序

#include <stdio.h>

void main() {
	int i,n;
	char g;
	double h;
	scanf("%d", &n);
	for (i=0;i<n;i++) {
		scanf(" %c %lf", &g, &h);
		if (g=='F') {
			printf("%.2f\n", h*1.09);
		} else if (g == 'M') 
		{
			printf("%.2f\n",h/1.09);
		}
	}
}
//ps:这样没办法一起输出完再输出