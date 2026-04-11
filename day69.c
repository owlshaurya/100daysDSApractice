#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Swap
void swap(struct HeapNode *a, struct HeapNode *b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap *h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if(right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

// Insert into heap
void insert(struct MinHeap *h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;

    while(i != 0 && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Extract min
struct HeapNode extractMin(struct MinHeap *h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapify(h, 0);
    return root;
}

// Dijkstra
void dijkstra(int V, int graph[MAX][MAX], int src) {
    int dist[MAX];

    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap h;
    h.size = 0;

    dist[src] = 0;
    insert(&h, src, 0);

    while(h.size > 0) {
        struct HeapNode minNode = extractMin(&h);
        int u = minNode.vertex;

        for(int v = 0; v < V; v++) {
            if(graph[u][v] && dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                insert(&h, v, dist[v]);
            }
        }
    }

    // Print result
    for(int i = 0; i < V; i++)
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
}

int main() {
    int V = 5;

    int graph[MAX][MAX] = {
        {0,2,4,0,0},
        {0,0,1,7,0},
        {0,0,0,0,3},
        {0,0,0,0,1},
        {0,0,0,0,0}
    };

    dijkstra(V, graph, 0);

    return 0;
}