#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct node {
    int vertex;
    struct node* next;
};

// Create node
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

// BFS function
void bfs(struct node* adj[], int n, int start) {
    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int queue[100];
    int front = 0, rear = 0;

    // Start from source
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct node* temp = adj[curr];

        while(temp != NULL) {
            int v = temp->vertex;

            if(!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }

            temp = temp->next;
        }
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
    scanf("%d", &s); // source

    bfs(adj, n, s);

    return 0;
}