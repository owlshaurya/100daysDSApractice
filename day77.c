#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

// DFS function
void dfs(int v, int n) {
    visited[v] = 1;

    for(int i = 1; i <= n; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        for(int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;

    // input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    // start DFS from node 1
    dfs(1, n);

    // check if all visited
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}