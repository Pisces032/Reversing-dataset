#include <stdio.h>

void main() {
    int A_capacity, B_capacity;  
    int n,i;
    int A_drunk = 0;   
    int B_drunk = 0;  
	int A_shout[100]={0}, A_gesture[100]={0}, B_shout[100]={0}, B_gesture[100]={0};
	int sum[100]={0};
	scanf("%d %d", &A_capacity, &B_capacity);
	scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d", &A_shout[i], &A_gesture[i], &B_shout[i], &B_gesture[i]);
		sum[i] = A_shout[i] + B_shout[i];}
	for (i = 0; i < n; i++){
        if ((A_gesture[i]== sum[i]) && (B_gesture[i]!= sum[i]) )         A_drunk++;
		else if ((B_gesture[i]== sum[i]) && (A_gesture[i]!= sum[1]))     B_drunk++;
        if (A_drunk > A_capacity) {printf("A\n%d\n", B_drunk);break;} 
		else if (B_drunk > B_capacity) {printf("B\n%d\n", A_drunk);break;}
    }
	getchar();
	getchar();
}