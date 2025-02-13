//ÌâÄ¿£ºµ¼µ¯À¹½Ø
#include<stdio.h>
int num[100000],f[100001],l[100001];
int main(){
    int n=0,fmax=1,llen=1;
    while(scanf("%d",&num[n])!=EOF){
        ++n;
    }
    f[1]=0;
    for(int i=1;i<n;i++){
        if(num[i]<=num[f[fmax]]){
            ++fmax;
            f[fmax]=i;
        }
        else if(fmax==1){
            f[fmax]=i;
        }
        else{
            for(int j=fmax-1;j>=1;j--){
                if(num[i]<=num[f[j]]){
                    if(num[i]>num[f[j+1]]){
                        f[j+1]=i;
                    }
                    break;
                }
                else if(j==1){
                    f[j]=i;
                }
            }
        }
    }
    l[1]=0;
    for(int i=1;i<n;i++){
        if(num[i]>num[l[llen]]){
            ++llen;
            l[llen]=i;
        }
        else{
            for(int j=1;j<=llen;j++){
                if(num[i]<=num[l[j]]){
                    l[j]=i;
                    break;
                }
            }
        }
        
    }
    
    printf("%d\n%d",fmax,llen);
    return 0;
}