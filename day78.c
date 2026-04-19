#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // initialize graph
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    int u, v, w;

    // input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX];
    int visited[MAX];

    // initialize
    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // start from node 1
    int totalWeight = 0;

    for(int i = 1; i <= n; i++) {

        int min = INT_MAX, u = -1;

        // pick minimum key node
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // update keys
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}