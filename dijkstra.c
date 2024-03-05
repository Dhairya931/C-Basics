#include<stdio.h>
#define INF 9999
#define MAX 10
void DA(int Graph[MAX][MAX],int size,int start);
void DA(int Graph[MAX][MAX],int size,int start){
    int cost[MAX][MAX],distance[MAX],previous[MAX],visited_nodes[MAX],counter,minimum_distance,next_node,i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(Graph[i][j]==0){
                cost[i][j]=INF;
            }
            else{
                cost[i][j]=Graph[i][j];
            }
        }
    }
    for(i=0;i<size;i++){
        distance[i]=cost[start][i];
        previous[i]=start;
        visited_nodes[i]=0;
    }
    distance[start]=0;
    visited_nodes[i]=0;
    counter=1;
    while(counter<size-1){
        minimum_distance=INF;
        for(i=0;i<size;i++){
            if(distance[i]<minimum_distance &&! visited_nodes[i]){
                minimum_distance=distance[i];
                next_node=i;
            }
        }
        visited_nodes[next_node]=1;
        for(i=0;i<size;i++){
            if(!visited_nodes[i])
            if(minimum_distance+cost[next_node][i]<distance[i]){
                distance[i]=minimum_distance+cost[next_node][i];
                previous[i]=next_node;
            }
        }
        counter++;
    }
    for(i=0;i<size;i++){
        if(i!=start){
            printf("\n Distance from source node to %d : %d",i,distance[i]);
        }
    }
}

int main(){
    int Graph[MAX][MAX],i,j,size,source,e;
    size=7;
    printf("Enter the vertices:");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%d",&Graph[i][j]);
        }
    }
    source=0;
    DA(Graph,size, source);
    return 0;
    
}