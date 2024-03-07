#include<stdio.h>
void main(){
    int n;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    for (int k = 1; k <= n; k++) { 
        for (int j = 1; j <= n - k; j++) 
            printf(" "); 
        int x = 1; 
        for (int i = 1; i <= k; i++) {  
            printf("%d ", x); 
            x = x * (k - i) / i; 
        } 
        printf("\n"); 
    } 
}