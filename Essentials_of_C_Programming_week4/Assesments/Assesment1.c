
#include "stdio.h"
int main(){
    int n;
    do { 
    printf("Enter the number from (1-7) to display the corresponding day:");
    scanf("%d",&n);
    }
    while(n<1||n>7); 
    
    switch (n){
        case 1:
        printf("Sunday");
        break;
        case 2:
        printf("Monday");
        break;
        case 3:
        printf("Tuesday");
        break;
        case 4:
        printf("wednesday");
        break;
        case 5:
        printf("Thursday");
        break;
        case 6:
        printf("Friday");
        break;
        case 7:
        printf("Saturday");
        break;
        default :
        break;
    }
    return 0;
}