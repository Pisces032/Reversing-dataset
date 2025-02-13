//ÌâÄ¿£º´ğÒÉ

#include <stdio.h>
#include <stdlib.h>
void change(int arr[], int brr[])
{
	for (int i = 0;i < 3;i++)
	{
		int tmp = 0;
		tmp = *(arr + i);
		*(arr + i) = *(brr + i);
		*(brr + i) = tmp;
	}
}

int main(int argc, char *argv[]){
	int i, j = 0;
	int n = 3;
	scanf("%d", &n);
	int arr[3][3]; //si=arr[i][0],ai=arr[i][1],ei=arr[i][2]
	for (i = 0;i < n;i++){
		scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	int tmp[3];
	for (i = 0;i < n;i++){
		for (j = i + 1;j < n;j++){
			if (arr[i][0] + arr[i][1] + arr[i][2] > arr[j][0] + arr[j][1] + arr[j][2]){
				change(arr[i], arr[j]);
			}
		}
	}

	long long sum = 0;
	long long last = 0;
	for (i = 0;i < n;i++){
		sum += arr[i][0] + arr[i][1] + last;
		last += arr[i][0] + arr[i][1] + arr[i][2];
	}
	printf("%lld", sum);
	return 0;
}
