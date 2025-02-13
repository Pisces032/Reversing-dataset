//题目：付账问题

#include<stdio.h>
#include<math.h>
void bubble(long long a[],int n){
    int i,j;
    for(i = 0; i < n; i++){
        int f = 0,c = 0;
        for(j = 0,f = 0; j < n - i; j++){
            if(a[j-1] > a[j]){
                c = a[j-1];
                a[j-1] = a[j];
                a[j] = c;
                f = 1;
            }
        }
        if(!f){
            break;
        }

    }
}
int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    long long a[500000];
    for(int i = 0; i <= n; i++){
        scanf("%lld",&a[i]);
    }
    bubble(a,n);

    double avg = 1.0 * s / n, sum = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] * (n+1-i) < s){
            sum += (a[i] - avg) * (a[i]-avg);
            s -= a[i];
        }
        else{
            double avg2 = 1.0 *s /(n-i+1);
            sum += (avg2 - avg) * (avg2 - avg) * (n+1-i);
            break;
        }
    }
    printf("%.4f",sqrt(sum/n));



    return 0;
}