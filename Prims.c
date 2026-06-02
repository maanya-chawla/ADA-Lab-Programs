#include <stdio.h>

#define MAX 10
#define INF 99999

int main() {
    int n;
    int graph[MAX][MAX];
    int selected[MAX] = {0};

    int edges = 0;
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    selected[0] = 1; 

    printf("\nEdges in MST:\n");

    while (edges < n - 1) {

        int min = INF;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++) {

            if (selected[i]) {

                for (int j = 0; j < n; j++) {

                    if (!selected[j] &&
                        graph[i][j] &&
                        graph[i][j] < min) {

                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);

        minCost += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}







