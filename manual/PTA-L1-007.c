#include<stdio.h>
int main()
{
	int a,b,c,d[1000],i=0;
	scanf("%d",&a);
	if(a<0)
	{
		printf("fu");
		a=-a;
	    c=1;
	}
	else if(a==0)
	{printf("ling");}
    b=a;           //������תΪ��������
	 if(a>0)
	{
		b=a;
		while(b>9)
		{
		d[i]=b%10;
		b=b/10;
		i++;        //ȡ����λ�ϵ��� 
		}
		d[i]=b;     //ȡ���һλ��
		for(int j=i;j>=0;j--)//�������
		{
			if(c==1)
			printf(" ");//��c�����ƿո����
			switch (d[j])
			{
				case 0:printf("ling");c=1;break;
				case 1:printf("yi");c=1;break;
				case 2:printf("er");c=1;break;
				case 3:printf("san");c=1;break;
				case 4:printf("si");c=1;break;
				case 5:printf("wu");c=1;break;
				case 6:printf("liu");c=1;break;
				case 7:printf("qi");c=1;break;
				case 8:printf("ba");c=1;break;
				case 9:printf("jiu");c=1;break;
			}
		}
	}
	return 0;
}
