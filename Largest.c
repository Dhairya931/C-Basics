#include <stdio.h>
#include <conio.h>
#include <limits.h>
  
int main(){
    int array[500], count, i;
    int max, secondMax;
      
    printf("Enter number of elements in array\n");
    scanf("%d", &count);
          
    printf("Enter %d numbers \n", count);
    for(i = 0; i < count; i++){
        scanf("%d", &array[i]);
    }
    /* Initialize max and secondMax 
       with INT_MIN */
      
    max = secondMax = INT_MIN;
      
    for(i = 0; i < count; i++){
        if(array[i] > max){
            secondMax = max;
            max = array[i];
        } else if (array[i] > secondMax 
            && array[i] < max){
            secondMax = array[i];
        }
    }
    /* Printing Maximum And Second Maximum element */
    printf("Maximum Element : %d \nSecond Maximum Element: %d", max, secondMax);
          
    getch();
    return 0;
}   