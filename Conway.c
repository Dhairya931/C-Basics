#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define R 6
#define C 6
int random=24;
int current[R+2][C+2];
int next[R+2][C+2];
int alive[R+2][C+2];

void main(){
    int i,j,a,b,sum;
    for (i=0;i<R+2;i++){
        for (j=0;j<C+2;j++){
            current[i][j]=0;
        }
    }

    for (i=1;i<=random;i++){
        a=1+(rand()%R);
        b=1+(rand()%C);
        current[a][b]=1;
    }

    printf("\n Population of current generation:\n");
    for(i=1;i<R+1;i++){
        for(j=1;j<C+1;j++){
            printf("%d\t",current[i][j]);
        }
        printf("\n");
    }
    
    for(i=1;i<R+1;i++){
        for(j=1;j<C+1;j++){
            sum=0;
            sum=sum+current[i-1][j-1];
            sum=sum+current[i-1][j];
            sum=sum+current[i-1][j+1];
            sum=sum+current[i][j-1];
            sum=sum+current[i][j+1];
            sum=sum+current[i+1][j-1];
            sum=sum+current[i+1][j];
            sum=sum+current[i+1][j+1];
            alive[i][j]=sum;

            if(current[i][j]==1){
                if(alive[i][j]<2||alive[i][j]>3){
                    next[i][j]=0;
                
                }
                else{
                    next[i][j]=1;
                }

            }
            else{
                if(alive[i][j]==3){
                    next[i][j]=1;
                }
                else{
                    next[i][j]=0;
                }
            }
        }
    }

    printf("\n Population of Next Generation:\n");
    for(i=1;i<R+1;i++){
        for(j=1;j<C+1;j++){
            printf("%d\t",next[i][j]);
        }
        printf("\n");
    }
}
