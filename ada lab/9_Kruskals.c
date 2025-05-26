#include <stdio.h>

#define INF 999

int parent[10];

// Find the root of a set
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union of two sets
void union_sets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int cost[10][10];
    int n, i, j;
    int min, u, v;
    int edges = 0, totalCost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("Edges in the Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;
        u = v = -1;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u != -1 && v != -1) {
            union_sets(u, v);
            printf("(%d, %d) = %d\n", u, v, min);
            totalCost += min;
            edges++;
        }
    }

    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
