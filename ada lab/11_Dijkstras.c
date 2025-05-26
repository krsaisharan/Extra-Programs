#include <stdio.h>

#define INF 999

int main() {
    int n, cost[10][10], distance[10], visited[10];
    int i, j, u, min, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (999 for no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    // Initialize distances and visited array
    for(i = 0; i < n; i++) {
        distance[i] = cost[src][i];
        visited[i] = 0;
    }

    distance[src] = 0;
    visited[src] = 1;

    for(i = 1; i < n; i++) {
        min = INF;
        u = -1;

        // Find the unvisited node with the smallest distance
        for(j = 0; j < n; j++) {
            if(!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances of neighbors of u
        for(j = 0; j < n; j++) {
            if(!visited[j] && distance[u] + cost[u][j] < distance[j]) {
                distance[j] = distance[u] + cost[u][j];
            }
        }
    }

    // Output shortest distances
    printf("\nShortest distances from vertex %d:\n", src);
    for(i = 0; i < n; i++) {
        printf("To %d: %d\n", i, distance[i]);
    }

    return 0;
}
