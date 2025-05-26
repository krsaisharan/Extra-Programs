#include <stdio.h>

#define INF 999

int main() {
    int cost[10][10], visited[10] = {0}, n, i, j;
    int minCost = 0;
    int edgeCount = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (enter 999 for no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1; // Start from the first vertex

    printf("Edges in the Minimum Spanning Tree:\n");

    while(edgeCount < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(u != -1 && v != -1) {
            printf("(%d, %d) = %d\n", u, v, cost[u][v]);
            visited[v] = 1;
            minCost += cost[u][v];
            edgeCount++;
        }
    }

    printf("Total cost of MST = %d\n", minCost);

    return 0;
}
