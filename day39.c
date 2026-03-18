#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (after insert)
void heapifyUp(int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

// Heapify down (after extract)
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Peek
void peek() {
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

// Extract Min
void extractMin() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

int main() {
    int n;
    scanf("%d", &n);

    char op[20];
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        }
        else if(strcmp(op, "peek") == 0) {
            peek();
        }
        else if(strcmp(op, "extractMin") == 0) {
            extractMin();
        }
    }

    return 0;
}