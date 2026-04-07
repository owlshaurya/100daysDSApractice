#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int adj[MAX][MAX];
int V;

// DFS function
bool dfs(int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            // If not visited → recurse
            if (!visited[i]) {
                if (dfs(i, visited, recStack))
                    return true;
            }
            // If already in recursion stack → cycle
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = false; // remove from stack
    return false;
}

// Function to detect cycle
bool isCycle() {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    if (isCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}