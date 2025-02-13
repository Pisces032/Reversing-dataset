#include <stdio.h>
int main() {
    int hour, minute,i;
    scanf("%d:%d",&hour,&minute);
    if (hour<12||(hour==12&&minute==0)){
        printf("Only %02d:%02d.  Too early to Dang.\n", hour, minute);
    } else {
        hour = hour % 12;
        if (hour==0) {
            hour=12;
        }
        if (minute>0){
            hour=(hour+1)%12;
            if (hour==0){
                hour=12;
            }
        }
        for (i = 0;i<hour;i++) {
            printf("Dang");
        }
        printf("\n");
    }
    return 0;
}