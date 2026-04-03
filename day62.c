#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct node {
    int vertex;
    struct node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct node** adjLists;
};

// Create new node
struct node* createNode(int v) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));

    for(int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {

    // Add dest to src
    struct node* newnode = createNode(dest);
    newnode->next = graph->adjLists[src];
    graph->adjLists[src] = newnode;

    // Add src to dest
    newnode = createNode(src);
    newnode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newnode;
}

// Print graph
void printGraph(struct Graph* graph) {
    for(int v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];

        printf("%d: ", v);

        while(temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);

    return 0;
}