#include <stdio.h>
int main()
{
	int a,b;int n;int i,j;int c[100][4];int sum;
	scanf("%d%d",&a,&b);
	scanf("%d",&n);
	for (i=0;i<n;i++){
		for (j=0;j<4;j++){
			scanf("%d",&c[i][j]);
		}
		sum=c[i][0]+c[i][2];
		if (((c[i][3]==sum)&&(c[i][1]==sum))||((c[i][3]!=sum)&&(c[i][1]!=sum)))continue;
		else if(c[i][1]==sum&&c[i][3]!=sum)a--;
		else if ((c[i][1]!=sum)&&(c[i][3]==sum))b--;
		if (a==0&&b>0){
			printf("A\n%d",b);
			break;
		}
		else if (a>0&&b==0){
			printf("B\n%d",a);
			break;
		}
	}
	printf("\n");
	return 0;
}
