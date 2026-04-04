#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct node {
    int vertex;
    struct node* next;
};

// Create new node
struct node* createNode(int v) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

// Add edge (undirected)
void addEdge(struct node* adj[], int u, int v) {
    struct node* newnode = createNode(v);
    newnode->next = adj[u];
    adj[u] = newnode;

    newnode = createNode(u);
    newnode->next = adj[v];
    adj[v] = newnode;
}

// DFS function
void dfs(struct node* adj[], int visited[], int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct node* temp = adj[v];
    while(temp != NULL) {
        if(!visited[temp->vertex]) {
            dfs(adj, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct node* adj[n];

    // Initialize
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    // Input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int s;
    scanf("%d", &s); // starting vertex

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(adj, visited, s);

    return 0;
}