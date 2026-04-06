#include <stdlib.h>

// Adjacency list node
struct Node {
    int val;
    struct Node* next;
};

// Add edge to adjacency list
void addEdge(struct Node** adj, int u, int v) {
    // u -> v
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    // v -> u (undirected)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS to detect cycle
int dfs(struct Node** adj, int* visited, int node, int parent) {
    visited[node] = 1;

    struct Node* curr = adj[node];
    while (curr != NULL) {
        int neighbor = curr->val;

        if (!visited[neighbor]) {
            // Visit unvisited neighbor
            if (dfs(adj, visited, neighbor, node))
                return 1;
        }