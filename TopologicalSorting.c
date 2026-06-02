#include<stdio.h>
#define Max 100
int graph[Max][Max];
int indegree[Max];
int queue[Max];
int front=0,rear=0;
int main(){
    int n,e;
    printf("Enter number of vertices: ");
    scanf("%d",&n); 
    printf("Enter number of edges: ");
    scanf("%d",&e);

    for(int i=0;i<n;i++){
        indegree[i] = 0;
        for(int j=0;j<n;j++){
            graph[i][j] = 0;
        }
    }
    printf("Enter edges (u v):\n");
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u][v] = 1; 
        indegree[v]++;
    }
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            queue[rear++] = i; 
        }
    }
    printf("Topological Sort: ");
    while(front < rear){
        int current = queue[front++];
        printf("%d ",current);
        for(int j=0;j<n;j++){
            if(graph[current][j] == 1){
                indegree[j]--;
                if(indegree[j] == 0){
                    queue[rear++] = j; 
                }
            }
        }
        return 0;
}