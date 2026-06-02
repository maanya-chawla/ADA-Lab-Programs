#include <stdio.h>

#define MAX 10

struct Edge {
    int u, v, w;
};

int parent[MAX];

// Find parent
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}


void unite(int a, int b) {
    parent[a] = b;
}


void sort(struct Edge e[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (e[j].w > e[j + 1].w) {
                struct Edge temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int graph[MAX][MAX];
    struct Edge edges[MAX * MAX];

    int edgeCount = 0;
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");

    for (int i = 0; i < n; i++) {
        parent[i] = i;

        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] != 0 && i < j) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].w = graph[i][j];
                edgeCount++;
            }
        }
    }

    sort(edges, edgeCount);

    printf("\nEdges in MST:\n");

    int count = 0;

    for (int i = 0; i < edgeCount && count < n - 1; i++) {

        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v) {
            printf("%d - %d : %d\n",
                edges[i].u,
                edges[i].v,
                edges[i].w);

            minCost += edges[i].w;
            unite(u, v);
            count++;
        }
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}